#line 1 "graphviz-2.38.0\\lib\\dotgen\\mincross.c" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/


/* 
 * dot_mincross(g) takes a ranked graphs, and finds an ordering
 * that avoids edge crossings.  clusters are expanded.
 * N.B. the rank structure is global (not allocated per cluster)
 * because mincross may compare nodes in different clusters.
 */

#line 1 "graphviz-2.38.0\\lib\\dotgen\\dot.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/





#line 1 "graphviz-2.38.0\\lib\\common\\render.h" 1


/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/









#line 1 "graphviz-2.38.0\\lib\\common\\render.h" 1


















#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1
/* lib/common/types.h.  Generated from types.h.in by configure.  */
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




/* Define if you want CGRAPH */


#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1
#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1
#line 1 "graphviz-2.38.0\\lib\\common\\types.h" 1

typedef unsigned char boolean;










#line 1 "graphviz-2.38.0\\lib\\common\\geom.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* geometric types and macros (e.g. points and boxes) with application to, but
 * no specific dependance on graphs */





#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* geometric functions (e.g. on points and boxes) with application to, but
 * no specific dependance on graphs */




/* for sincos */




#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1



#line 1 "graphviz-2.38.0\\lib\\common\\arith.h" 1
































































    









#line 20 "graphviz-2.38.0\\lib\\common\\geom.h" 2





    
typedef struct { int x, y; } point;

typedef struct pointf_s { double x, y; } pointf;

/* tell pathplan/pathgeom.h */


typedef struct { point LL, UR; } box;

typedef struct { pointf LL, UR; } boxf;



/* true if point p is inside box b */


/* true if boxes b0 and b1 overlap */


/* true if box b0 completely contains b1*/


/* expand box b as needed to enclose point p */


/* expand box b0 as needed to enclose box b1 */


/* clip box b0 to fit box b1 */


























/* some common tolerance values */










#line 27 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcext.h" 1

/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Common header used by both clients and plugins */








/*
 * Define an apis array of name strings using an enumerated api_t as index.
 * The enumerated type is defined here.  The apis array is
 * inititialized in gvplugin.c by redefining ELEM and reinvoking APIS.
 */


/*
 * Define api_t using names based on the plugin names with API_ prefixed.
 */

    typedef enum { API_render, API_layout, API_textlayout, API_device, API_loadimage, _DUMMY_ELEM_=0 } api_t; /* API_render, API_layout, ... */
    			/* Stupid but true: The sole purpose of "_DUMMY_ELEM_=0"
			 * is to avoid a "," after the last element of the enum
			 * because some compilers when using "-pedantic"
			 * generate an error for about the dangling ","
			 * but only if this header is used from a .cpp file!
			 * Setting it to 0 makes sure that the enumeration
			 * does not define an extra value.  (It does however
			 * define _DUMMY_ELEM_ as an enumeration symbol,
			 * but its value duplicates that of the first
			 * symbol in the enumeration - in this case "render".)
			 */

    			/* One could wonder why trailing "," in:
			 * 	int nums[]={1,2,3,};
			 * is OK, but in:
			 * 	typedef enum {a,b,c,} abc_t; 
			 * is not!!!
			 */


    typedef struct GVJ_s GVJ_t;
    typedef struct GVG_s GVG_t;
    typedef struct GVC_s GVC_t;

    typedef struct {
	const char *name;
	void* address;
    } lt_symlist_t;

    typedef struct gvplugin_available_s gvplugin_available_t;

/*visual studio*/








/*end visual studio*/




	


	extern lt_symlist_t lt_preloaded_symbols[];












#line 28 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\pathplan\\pathgeom.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/










    typedef struct pointf_s Ppoint_t;
    typedef struct pointf_s Pvector_t;

    
	
    

    
    


    typedef struct Ppoly_t {
	Ppoint_t *ps;
	int pn;
    } Ppoly_t;

    typedef Ppoly_t Ppolyline_t;

    typedef struct Pedge_t {
	Ppoint_t a, b;
    } Pedge_t;

/* opaque state handle for visibility graph operations */
    typedef struct vconfig_s vconfig_t;

    void freePath(Ppolyline_t* p);




#line 29 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\textspan.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/








/* Bold, Italic, Underline, Sup, Sub, Strike */
/* Stored in textfont_t.flags, which is 7 bits, so full */
/* Probably should be moved to textspan_t */








    typedef struct _PostscriptAlias {
        char* name;
        char* family;
        char* weight;
        char* stretch;
        char* style;
        int xfig_code;
	char* svg_font_family;
	char* svg_font_weight;
	char* svg_font_style;
    } PostscriptAlias;

    /* font information
     * If name or color is NULL, or size < 0, that attribute
     * is unspecified. 
     */
    typedef struct {
	char*  name;
	char*  color;
	PostscriptAlias *postscript_alias;
	double size;
	unsigned int flags:7;  /* HTML_UL, HTML_IF, HTML_BF, etc. */
	unsigned int cnt:(sizeof(unsigned int) * 8 - 7);   /* reference count */
    } textfont_t;

    /* atomic unit of text emitted using a single htmlfont_t */
    typedef struct {
	char *str;      /* stored in utf-8 */
	textfont_t *font;
	void *layout;
	void (*free_layout) (void *layout);   /* FIXME - this is ugly */
	double yoffset_layout, yoffset_centerline;
 	pointf size;
	char just;	/* 'l' 'n' 'r' */ /* FIXME */
    } textspan_t;





#line 30 "graphviz-2.38.0\\lib\\common\\types.h" 2
#line 1 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1



/*	Public interface for the dictionary library
**
**      Written by Kiem-Phong Vo
*/











#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1
#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1






















typedef struct _dtlink_s	Dtlink_t;
typedef struct _dthold_s	Dthold_t;
typedef struct _dtdisc_s	Dtdisc_t;
typedef struct _dtmethod_s	Dtmethod_t;
typedef struct _dtdata_s	Dtdata_t;
typedef struct _dt_s		Dt_t;
typedef struct _dt_s		Dict_t;	/* for libdict compatibility */
typedef struct _dtstat_s	Dtstat_t;
typedef void*			(*Dtmemory_f)(Dt_t*,void*,size_t,Dtdisc_t*);
typedef void*			(*Dtsearch_f)(Dt_t*,void*,int);
typedef void* 		(*Dtmake_f)(Dt_t*,void*,Dtdisc_t*);
typedef void 			(*Dtfree_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtcompar_f)(Dt_t*,void*,void*,Dtdisc_t*);
typedef unsigned int		(*Dthash_f)(Dt_t*,void*,Dtdisc_t*);
typedef int			(*Dtevent_f)(Dt_t*,int,void*,Dtdisc_t*);

struct _dtlink_s
{	Dtlink_t*	right;	/* right child		*/
	union
	{ unsigned int	_hash;	/* hash value		*/
	  Dtlink_t*	_left;	/* left child		*/
	} hl;
};

/* private structure to hold an object */
struct _dthold_s
{	Dtlink_t	hdr;	/* header		*/
	void*		obj;	/* user object		*/
};

/* method to manipulate dictionary structure */
struct _dtmethod_s 
{	Dtsearch_f	searchf; /* search function	*/
	int		type;	/* type of operation	*/
};

/* stuff that may be in shared memory */
struct _dtdata_s
{	int		type;	/* type of dictionary			*/
	Dtlink_t*	here;	/* finger to last search element	*/
	union
	{ Dtlink_t**	_htab;	/* hash table				*/
	  Dtlink_t*	_head;	/* linked list				*/
	} hh;
	int		ntab;	/* number of hash slots			*/
	int		size;	/* number of objects			*/
	int		loop;	/* number of nested loops		*/
	int		minp;	/* min path before splay, always even	*/
				/* for hash dt, > 0: fixed table size 	*/
};

/* structure to hold methods that manipulate an object */
struct _dtdisc_s
{	int		key;	/* where the key begins in an object	*/
	int		size;	/* key size and type			*/
	int		link;	/* offset to Dtlink_t field		*/
	Dtmake_f	makef;	/* object constructor			*/
	Dtfree_f	freef;	/* object destructor			*/
	Dtcompar_f	comparf;/* to compare two objects		*/
	Dthash_f	hashf;	/* to compute hash value of an object	*/
	Dtmemory_f	memoryf;/* to allocate/free memory		*/
	Dtevent_f	eventf;	/* to process events			*/
};













/* the dictionary structure itself */
struct _dt_s
{	Dtsearch_f	searchf;/* search function			*/
	Dtdisc_t*	disc;	/* method to manipulate objs		*/
	Dtdata_t*	data;	/* sharable data			*/
	Dtmemory_f	memoryf;/* function to alloc/free memory	*/
	Dtmethod_t*	meth;	/* dictionary method			*/
	int		type;	/* type information			*/
	int		nview;	/* number of parent view dictionaries	*/
	Dt_t*		view;	/* next on viewpath			*/
	Dt_t*		walk;	/* dictionary being walked		*/
	void*		user;	/* for user's usage			*/
};

/* structure to get status of a dictionary */
struct _dtstat_s
{	int	dt_meth;	/* method type				*/
	int	dt_size;	/* number of elements			*/
	int	dt_n;		/* number of chains or levels		*/
	int	dt_max;		/* max size of a chain or a level	*/
	int*	dt_count;	/* counts of chains or levels by size	*/
};

/* flag set if the last search operation actually found the object */


/* supported storage methods */










/* asserts to dtdisc() */



/* types of search */















/* events */








1	/* public data */







extern Dtmethod_t* 	Dtset;
extern Dtmethod_t* 	Dtbag;
extern Dtmethod_t* 	Dtoset;
extern Dtmethod_t* 	Dtobag;
extern Dtmethod_t*	Dtlist;
extern Dtmethod_t*	Dtstack;
extern Dtmethod_t*	Dtqueue;
extern Dtmethod_t*	Dtdeque;

/* compatibility stuff; will go away */

extern Dtmethod_t*	Dtorder;
extern Dtmethod_t*	Dttree;
extern Dtmethod_t*	Dthash;
extern Dtmethod_t	_Dttree;
extern Dtmethod_t	_Dthash;
extern Dtmethod_t	_Dtlist;
extern Dtmethod_t	_Dtqueue;
extern Dtmethod_t	_Dtstack;





1	/* public functions */




extern Dt_t*		dtopen (Dtdisc_t*, Dtmethod_t*);
extern int		dtclose (Dt_t*);
extern Dt_t*		dtview (Dt_t*, Dt_t*);
extern Dtdisc_t*	dtdisc (Dt_t* dt, Dtdisc_t*, int);
extern Dtmethod_t*	dtmethod (Dt_t*, Dtmethod_t*);

extern Dtlink_t*	dtflatten (Dt_t*);
extern Dtlink_t*	dtextract (Dt_t*);
extern int		dtrestore (Dt_t*, Dtlink_t*);

extern int		dttreeset (Dt_t*, int, int);

extern int		dtwalk (Dt_t*, int(*)(Dt_t*,void*,void*), void*);

extern void*		dtrenew (Dt_t*, void*);

extern int		dtsize (Dt_t*);
extern int		dtstat (Dt_t*, Dtstat_t*, int);
extern unsigned int	dtstrhash (unsigned int, void*, int);











/* internal functions for translating among holder, object and key */












/* special search function for tree structure only */

























































#line 17 "graphviz-2.38.0\\lib\\cgraph\\cgraph.h" 2






















/* forward struct type declarations */
typedef struct Agtag_s Agtag_t;
typedef struct Agobj_s Agobj_t;	/* generic object header */
typedef struct Agraph_s Agraph_t;	/* graph, subgraph (or hyperedge) */
typedef struct Agnode_s Agnode_t;	/* node (atom) */
typedef struct Agedge_s Agedge_t;	/* node pair */
typedef struct Agdesc_s Agdesc_t;	/* graph descriptor */
typedef struct Agmemdisc_s Agmemdisc_t;	/* memory allocator */
typedef struct Agiddisc_s Agiddisc_t;	/* object ID allocator */
typedef struct Agiodisc_s Agiodisc_t;	/* IO services */
typedef struct Agdisc_s Agdisc_t;	/* union of client discipline methods */
typedef struct Agdstate_s Agdstate_t;	/* client state (closures) */
typedef struct Agsym_s Agsym_t;	/* string attribute descriptors */
typedef struct Agattr_s Agattr_t;	/* string attribute container */
typedef struct Agcbdisc_s Agcbdisc_t;	/* client event callbacks */
typedef struct Agcbstack_s Agcbstack_t;	/* enclosing state for cbdisc */
typedef struct Agclos_s Agclos_t;	/* common fields for graph/subgs */
typedef struct Agrec_s Agrec_t;	/* generic runtime record */
typedef struct Agdatadict_s Agdatadict_t;	/* set of dictionaries per graph */
typedef struct Agedgepair_s Agedgepair_t;	/* the edge object */
typedef struct Agsubnode_s Agsubnode_t;

/* Header of a user record.  These records are attached by client programs
dynamically at runtime.  A unique string ID must be given to each record
attached to the same object.  Cgraph has functions to create, search for,
and delete these records.   The records are maintained in a circular list,
with obj->data pointing somewhere in the list.  The search function has
an option to lock this pointer on a given record.  The application must
be written so only one such lock is outstanding at a time. */

struct Agrec_s {
    char *name;
    Agrec_t *next;
    /* following this would be any programmer-defined data */
};

/* Object tag for graphs, nodes, and edges.  While there may be several structs
for a given node or edges, there is only one unique ID (per main graph).  */
struct Agtag_s {
    unsigned objtype:2;		/* see literal tags below */
    unsigned mtflock:1;		/* move-to-front lock, see above */
    unsigned attrwf:1;		/* attrs written (parity, write.c) */
    unsigned seq:(sizeof(unsigned) * 8 - 4);	/* sequence no. */
    unsigned long id;		/* client  ID */
};

	/* object tags */






	/* a generic graph/node/edge header */
struct Agobj_s {
    Agtag_t tag;
    Agrec_t *data;
};








/* This is the node struct allocated per graph (or subgraph).  It resides
in the n_dict of the graph.  The node set is maintained by libdict, but
transparently to libgraph callers.  Every node may be given an optional
string name at its time of creation, or it is permissible to pass NIL(char*)
for the name. */

struct Agsubnode_s {		/* the node-per-graph-or-subgraph record */
    Dtlink_t seq_link;		/* must be first */
    Dtlink_t id_link;
    Agnode_t *node;		/* the object */
    Dtlink_t *in_id, *out_id;	/* by node/ID for random access */
    Dtlink_t *in_seq, *out_seq;	/* by node/sequence for serial access */
};

struct Agnode_s {
    Agobj_t base;
    Agraph_t *root;
    Agsubnode_t mainsub;	/* embedded for main graph */
};

struct Agedge_s {
    Agobj_t base;
    Dtlink_t id_link;		/* main graph only */
    Dtlink_t seq_link;
    Agnode_t *node;		/* the endpoint node */
};

struct Agedgepair_s {
    Agedge_t out, in;
};

struct Agdesc_s {		/* graph descriptor */
    unsigned directed:1;	/* if edges are asymmetric */
    unsigned strict:1;		/* if multi-edges forbidden */
    unsigned no_loop:1;		/* if no loops */
    unsigned maingraph:1;	/* if this is the top level graph */
    unsigned flatlock:1;	/* if sets are flattened into lists in cdt */
    unsigned no_write:1;	/* if a temporary subgraph */
    unsigned has_attrs:1;	/* if string attr tables should be initialized */
    unsigned has_cmpnd:1;	/* if may contain collapsed nodes */
};

/* disciplines for external resources needed by libgraph */

struct Agmemdisc_s {		/* memory allocator */
    void *(*open) (Agdisc_t*);	/* independent of other resources */
    void *(*alloc) (void *state, size_t req);
    void *(*resize) (void *state, void *ptr, size_t old, size_t req);
    void (*free) (void *state, void *ptr);
    void (*close) (void *state);
};

struct Agiddisc_s {		/* object ID allocator */
    void *(*open) (Agraph_t * g, Agdisc_t*);	/* associated with a graph */
    long (*map) (void *state, int objtype, char *str, unsigned long *id,
		 int createflag);
    long (*alloc) (void *state, int objtype, unsigned long id);
    void (*free) (void *state, int objtype, unsigned long id);
    char *(*print) (void *state, int objtype, unsigned long id);
    void (*close) (void *state);
    void (*idregister) (void *state, int objtype, void *obj);
};

struct Agiodisc_s {
    int (*afread) (void *chan, char *buf, int bufsize);
    int (*putstr) (void *chan, const char *str);
    int (*flush) (void *chan);	/* sync */
    /* error messages? */
};

struct Agdisc_s {		/* user's discipline */
    Agmemdisc_t *mem;
    Agiddisc_t *id;
    Agiodisc_t *io;
};

	/* default resource disciplines */

/*visual studio*/



/*end visual studio*/

extern Agmemdisc_t AgMemDisc;
extern Agiddisc_t AgIdDisc;
extern Agiodisc_t AgIoDisc;

extern Agdisc_t AgDefaultDisc;


struct Agdstate_s {
    void *mem;
    void *id;
    /* IO must be initialized and finalized outside Cgraph,
     * and channels (FILES) are passed as void* arguments. */
};

typedef void (*agobjfn_t) (Agraph_t * g, Agobj_t * obj, void *arg);
typedef void (*agobjupdfn_t) (Agraph_t * g, Agobj_t * obj, void *arg,
			      Agsym_t * sym);

struct Agcbdisc_s {
    struct {
	agobjfn_t ins;
	agobjupdfn_t mod;
	agobjfn_t del;
    } graph, node, edge;
};

struct Agcbstack_s {		/* object event callbacks */
    Agcbdisc_t *f;		/* methods */
    void *state;		/* closure */
    Agcbstack_t *prev;		/* kept in a stack, unlike other disciplines */
};

struct Agclos_s {
    Agdisc_t disc;		/* resource discipline functions */
    Agdstate_t state;		/* resource closures */
    Dict_t *strdict;		/* shared string dict */
    unsigned long seq[3];	/* local object sequence number counter */
    Agcbstack_t *cb;		/* user and system callback function stacks */
    unsigned char callbacks_enabled;	/* issue user callbacks or hold them? */
    Dict_t *lookup_by_name[3];
    Dict_t *lookup_by_id[3];
};

struct Agraph_s {
    Agobj_t base;
    Agdesc_t desc;
    Dtlink_t link;
    Dict_t *n_seq;		/* the node set in sequence */
    Dict_t *n_id;		/* the node set indexed by ID */
    Dict_t *e_seq, *e_id;	/* holders for edge sets */
    Dict_t *g_dict;		/* subgraphs - descendants */
    Agraph_t *parent, *root;	/* subgraphs - ancestors */
    Agclos_t *clos;		/* shared resources */
};












extern void agpushdisc(Agraph_t * g, Agcbdisc_t * disc, void *state);
extern int agpopdisc(Agraph_t * g, Agcbdisc_t * disc);
extern int agcallbacks(Agraph_t * g, int flag);	/* return prev value */

/* graphs */
extern Agraph_t *agopen(char *name, Agdesc_t desc, Agdisc_t * disc);
extern int agclose(Agraph_t * g);
extern Agraph_t *agread(void *chan, Agdisc_t * disc);
extern Agraph_t *agmemread(const char *cp);
extern void agreadline(int);
extern void agsetfile(char *);
extern Agraph_t *agconcat(Agraph_t * g, void *chan, Agdisc_t * disc);
extern int agwrite(Agraph_t * g, void *chan);
extern int agisdirected(Agraph_t * g);
extern int agisundirected(Agraph_t * g);
extern int agisstrict(Agraph_t * g);
extern int agissimple(Agraph_t * g);

/* nodes */
extern Agnode_t *agnode(Agraph_t * g, char *name, int createflag);
extern Agnode_t *agidnode(Agraph_t * g, unsigned long id, int createflag);
extern Agnode_t *agsubnode(Agraph_t * g, Agnode_t * n, int createflag);
extern Agnode_t *agfstnode(Agraph_t * g);
extern Agnode_t *agnxtnode(Agraph_t * g, Agnode_t * n);
extern Agnode_t *aglstnode(Agraph_t * g);
extern Agnode_t *agprvnode(Agraph_t * g, Agnode_t * n);

extern Agsubnode_t *agsubrep(Agraph_t * g, Agnode_t * n);

/* edges */
extern Agedge_t *agedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			char *name, int createflag);
extern Agedge_t *agidedge(Agraph_t * g, Agnode_t * t, Agnode_t * h,
			  unsigned long id, int createflag);
extern Agedge_t *agsubedge(Agraph_t * g, Agedge_t * e, int createflag);
extern Agedge_t *agfstin(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtin(Agraph_t * g, Agedge_t * e);
extern Agedge_t *agfstout(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtout(Agraph_t * g, Agedge_t * e);
extern Agedge_t *agfstedge(Agraph_t * g, Agnode_t * n);
extern Agedge_t *agnxtedge(Agraph_t * g, Agedge_t * e, Agnode_t * n);

/* generic */
extern Agraph_t *agraphof(void* obj);
extern Agraph_t *agroot(void* obj);
extern int agcontains(Agraph_t *, void *);
extern char *agnameof(void *);
extern int agrelabel(void *obj, char *name);	/* scary */
extern int agrelabel_node(Agnode_t * n, char *newname);
extern int agdelete(Agraph_t * g, void *obj);
extern long agdelsubg(Agraph_t * g, Agraph_t * sub);	/* could be agclose */
extern int agdelnode(Agraph_t * g, Agnode_t * arg_n);
extern int agdeledge(Agraph_t * g, Agedge_t * arg_e);
extern int agobjkind(void *);

/* strings */
extern char *agstrdup(Agraph_t *, char *);
extern char *agstrdup_html(Agraph_t *, char *);
extern int aghtmlstr(char *);
extern char *agstrbind(Agraph_t * g, char *);
extern int agstrfree(Agraph_t *, char *);
extern char *agcanon(char *, int);
extern char *agstrcanon(char *, char *);
extern char *agcanonStr(char *str);  /* manages its own buf */

/* definitions for dynamic string attributes */
struct Agattr_s {		/* dynamic string attributes */
    Agrec_t h;			/* common data header */
    Dict_t *dict;		/* shared dict to interpret attr field */
    char **str;			/* the attribute string values */
};

struct Agsym_s {		/* symbol in one of the above dictionaries */
    Dtlink_t link;
    char *name;			/* attribute's name */
    char *defval;		/* its default value for initialization */
    int id;			/* its index in attr[] */
    unsigned char kind;		/* referent object type */
    unsigned char fixed;	/* immutable value */
    unsigned char print;	/* always print */
};

struct Agdatadict_s {		/* set of dictionaries per graph */
    Agrec_t h;			/* installed in list of graph recs */
    struct {
	Dict_t *n, *e, *g;
    } dict;
};

extern Agsym_t *agattr(Agraph_t * g, int kind, char *name, char *value);
extern Agsym_t *agattrsym(void *obj, char *name);
extern Agsym_t *agnxtattr(Agraph_t * g, int kind, Agsym_t * attr);
extern int      agcopyattr(void *oldobj, void *newobj);

extern void *agbindrec(void *obj, char *name, unsigned int size,
		       int move_to_front);
extern Agrec_t *aggetrec(void *obj, char *name, int move_to_front);
extern int agdelrec(void *obj, char *name);
extern void aginit(Agraph_t * g, int kind, char *rec_name, int rec_size,
		   int move_to_front);
extern void agclean(Agraph_t * g, int kind, char *rec_name);

extern char *agget(void *obj, char *name);
extern char *agxget(void *obj, Agsym_t * sym);
extern int agset(void *obj, char *name, char *value);
extern int agxset(void *obj, Agsym_t * sym, char *value);
extern int agsafeset(void* obj, char* name, char* value, char* def);

/* defintions for subgraphs */
extern Agraph_t *agsubg(Agraph_t * g, char *name, int cflag);	/* constructor */
extern Agraph_t *agidsubg(Agraph_t * g, unsigned long id, int cflag);	/* constructor */
extern Agraph_t *agfstsubg(Agraph_t * g), *agnxtsubg(Agraph_t * subg);
extern Agraph_t *agparent(Agraph_t * g);

/* set cardinality */
extern int agnnodes(Agraph_t * g), agnedges(Agraph_t * g), agnsubg(Agraph_t * g);
extern int agdegree(Agraph_t * g, Agnode_t * n, int in, int out);
extern int agcountuniqedges(Agraph_t * g, Agnode_t * n, int in, int out);

/* memory */
extern void *agalloc(Agraph_t * g, size_t size);
extern void *agrealloc(Agraph_t * g, void *ptr, size_t oldsize,
		       size_t size);
extern void agfree(Agraph_t * g, void *ptr);
extern struct _vmalloc_s *agheap(Agraph_t * g);

/* an engineering compromise is a joy forever */
extern void aginternalmapclearlocalnames(Agraph_t * g);




/* error handling */
typedef enum { AGWARN, AGERR, AGMAX, AGPREV } agerrlevel_t;
typedef int (*agusererrf) (char*);
extern agerrlevel_t agseterr(agerrlevel_t);
extern char *aglasterr(void);
extern int agerr(agerrlevel_t level, const char *fmt, ...);
extern void agerrorf(const char *fmt, ...);
extern void agwarningf(const char *fmt, ...);
extern int agerrors(void);
extern int agreseterrors(void);
extern agusererrf agseterrf(agusererrf);

/* data access macros */
/* this assumes that e[0] is out and e[1] is inedge, see edgepair in edge.c  */
























extern Agdesc_t Agdirected, Agstrictdirected, Agundirected,
    Agstrictundirected;



/* fast graphs */
void agflatten(Agraph_t * g, int flag);
typedef Agsubnode_t	Agnoderef_t;
typedef Dtlink_t	Agedgeref_t;



















/* this is expedient but a bit slimey because it "knows" that dict entries of both nodes
and edges are embedded in main graph objects but allocated separately in subgraphs */











#line 31 "graphviz-2.38.0\\lib\\common\\types.h" 2





    typedef int (*qsort_cmpf) (const void *, const void *);
    typedef int (*bsearch_cmpf) (const void *, const void *);
    typedef struct Agraph_s graph_t;
    typedef struct Agnode_s node_t;
    typedef struct Agedge_s edge_t;
    typedef struct Agsym_s attrsym_t;



    typedef struct htmllabel_t htmllabel_t;

    typedef union inside_t {
	struct {
	    pointf* p;
	    double* r;
	} a;
	struct {
	    node_t* n;
	    boxf*    bp;
	} s;
    } inside_t;

    typedef struct port {	/* internal edge endpoint specification */
	pointf p;		/* aiming point relative to node center */
	double theta;		/* slope in radians */
	boxf *bp;		/* if not null, points to bbox of 
				 * rectangular area that is port target
				 */
	boolean	defined;        /* if true, edge has port info at this end */
	boolean	constrained;    /* if true, constraints such as theta are set */
	boolean clip;           /* if true, clip end to node/port shape */
	boolean dyna;           /* if true, assign compass point dynamically */
	unsigned char order;	/* for mincross */
	unsigned char side;	/* if port is on perimeter of node, this
                                 * contains the bitwise OR of the sides (TOP,
                                 * BOTTOM, etc.) it is on. 
                                 */
	char *name;		/* port name, if it was explicitly given, otherwise NULL */
    } port;

    typedef struct {
	boolean(*swapEnds) (edge_t * e);	/* Should head and tail be swapped? */
	boolean(*splineMerge) (node_t * n);	/* Is n a node in the middle of an edge? */
	boolean ignoreSwap;                     /* Test for swapped edges if false */
	boolean isOrtho;                        /* Orthogonal routing used */
    } splineInfo;

    typedef struct pathend_t {
	boxf nb;			/* the node box */
	pointf np;		/* node port */
	int sidemask;
	int boxn;
	boxf boxes[20];
    } pathend_t;

    typedef struct path {	/* internal specification for an edge spline */
	port start, end;
	int nbox;		/* number of subdivisions */
	boxf *boxes;		/* rectangular regions of subdivision */
	void *data;
    } path;

    typedef struct bezier {
	pointf *list;
	int size;
	int sflag, eflag;
	pointf sp, ep;
    } bezier;

    typedef struct splines {
	bezier *list;
	int size;
	boxf bb;
    } splines;

    typedef struct textlabel_t {
	char *text, *fontname, *fontcolor;
	int charset;
	double fontsize;
	pointf dimen; /* the diagonal size of the label (estimated by layout) */
	pointf space; /* the diagonal size of the space for the label */
		      /*   the rendered label is aligned in this box */
		      /*   space does not include pad or margin */
	pointf pos;   /* the center of the space for the label */
	union {
	    struct {
		textspan_t *span;
		short nspans;
	    } txt;
	    htmllabel_t *html;
	} u;
	char valign;  /* 't' 'c' 'b' */
	boolean set;  /* true if position is set */
	boolean html; /* true if html label */
    } textlabel_t;

    typedef struct polygon_t {	/* mutable shape information for a node */
	int regular;		/* true for symmetric shapes */
	int peripheries;	/* number of periphery lines */
	int sides;		/* number of sides */
	double orientation;	/* orientation of shape (+ve degrees) */
	double distortion;	/* distortion factor - as in trapezium */
	double skew;		/* skew factor - as in parallelogram */
	int option;		/* ROUNDED, DIAGONAL corners, etc. */
	pointf *vertices;	/* array of vertex points */
    } polygon_t;

    typedef struct stroke_t {	/* information about a single stroke */
	/* we would have called it a path if that term wasn't already used */
	int nvertices;		/* number of points in the stroke */
	int flags;		/* stroke style flags */
	pointf *vertices;	/* array of vertex points */
    } stroke_t;

/* flag definitions for stroke_t */





    typedef struct shape_t {	/* mutable shape information for a node */
	int nstrokes;		/* number of strokes in array */
	stroke_t *strokes;	/* array of strokes */
	/* The last stroke must always be closed, but can be pen_up.
	 * It is used as the clipping path */
    } shape_t;

    typedef struct shape_functions {	/* read-only shape functions */
	void (*initfn) (node_t *);	/* initializes shape from node u.shape_info structure */
	void (*freefn) (node_t *);	/* frees  shape from node u.shape_info structure */
	 port(*portfn) (node_t *, char *, char *);	/* finds aiming point and slope of port */
	 boolean(*insidefn) (inside_t * inside_context, pointf);	/* clips incident gvc->e spline on shape of gvc->n */
	int (*pboxfn)(node_t* n, port* p, int side, boxf rv[], int *kptr); /* finds box path to reach port */
	void (*codefn) (GVJ_t * job, node_t * n);	/* emits graphics code for node */
    } shape_functions;

    typedef enum { SH_UNSET, SH_POLY, SH_RECORD, SH_POINT, SH_EPSF} shape_kind;

    typedef struct shape_desc {	/* read-only shape descriptor */
	char *name;		/* as read from graph file */
	shape_functions *fns;
	polygon_t *polygon;	/* base polygon info */
	boolean usershape;
    } shape_desc;

#line 1 "graphviz-2.38.0\\lib\\common\\usershape.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 17 "graphviz-2.38.0\\lib\\common\\usershape.h" 2





    typedef enum { FT_NULL,
	FT_BMP, FT_GIF, FT_PNG, FT_JPEG,
	FT_PDF, FT_PS, FT_EPS, FT_SVG, FT_XML,
	FT_RIFF, FT_WEBP, FT_ICO, FT_TIFF
    } imagetype_t;

    typedef enum {
	IMAGESCALE_FALSE,  /* no image scaling */
	IMAGESCALE_TRUE,   /* scale image to fit but keep aspect ratio */
	IMAGESCALE_WIDTH,  /* scale image width to fit, keep height fixed */
	IMAGESCALE_HEIGHT, /* scale image height to fit, keep width fixed */
	IMAGESCALE_BOTH    /* scale image to fit without regard for aspect ratio */
    } imagescale_t;

    typedef struct usershape_s usershape_t;

    struct usershape_s {
	Dtlink_t link;
	const char *name;
	int macro_id;
	boolean must_inline;
	boolean nocache;
	FILE *f;
	imagetype_t type;
	char *stringtype;
	int x, y, w, h, dpi;
	void *data;                   /* data loaded by a renderer */
	size_t datasize;              /* size of data (if mmap'ed) */
	void (*datafree)(usershape_t *us); /* renderer's function for freeing data */
    };





#line 180 "graphviz-2.38.0\\lib\\common\\types.h" 2

    typedef struct nodequeue {
	node_t **store, **limit, **head, **tail;
    } nodequeue;

    typedef struct adjmatrix_t {
	int nrows, ncols;
	char *data;
    } adjmatrix_t;

    typedef struct rank_t {
	int n;			/* number of nodes in this rank  */
	node_t **v;		/* ordered list of nodes in rank    */
	int an;			/* globally allocated number of nodes   */
	node_t **av;		/* allocated list of nodes in rank  */
	double ht1, ht2;	/* height below/above centerline    */
	double pht1, pht2;	/* as above, but only primitive nodes   */
	boolean candidate;	/* for transpose () */
	boolean valid;
	int cache_nc;		/* caches number of crossings */
	adjmatrix_t *flat;
    } rank_t;

    typedef enum { R_NONE =
	    0, R_VALUE, R_FILL, R_COMPRESS, R_AUTO, R_EXPAND } ratio_t;

    typedef struct layout_t {
	double quantum;
	double scale;
	double ratio;		/* set only if ratio_kind == R_VALUE */
	double dpi;
	pointf margin;
	pointf page;
	pointf size;
	boolean filled;
	boolean landscape;
	boolean centered;
	ratio_t ratio_kind;
	void* xdots;
	char* id;
    } layout_t;

/* for "record" shapes */
    typedef struct field_t {
	pointf size;		/* its dimension */
	boxf b;			/* its placement in node's coordinates */
	int n_flds;
	textlabel_t *lp;	/* n_flds == 0 */
	struct field_t **fld;	/* n_flds > 0 */
	char *id;		/* user's identifier */
	unsigned char LR;	/* if box list is horizontal (left to right) */
	unsigned char sides;    /* sides of node exposed to field */
    } field_t;

    typedef struct nlist_t {
	node_t **list;
	int size;
    } nlist_t;

    typedef struct elist {
	edge_t **list;
	int size;
    } elist;











typedef enum {NATIVEFONTS,PSFONTS,SVGFONTS} fontname_kind;

    typedef struct Agraphinfo_t {
	Agrec_t hdr;
	/* to generate code */
	layout_t *drawing;
	textlabel_t *label;	/* if the cluster has a title */
	boxf bb;			/* bounding box */
	pointf border[4];	/* sizes of margins for graph labels */
	unsigned char gui_state; /* Graph state for GUI ops */
	unsigned char has_labels;
	boolean has_images;
	unsigned char charset; /* input character set */
	int rankdir;
	double ht1, ht2;	/* below and above extremal ranks */
	unsigned short flags;
	void *alg;
	GVC_t *gvc;	/* context for "globals" over multiple graphs */
	void (*cleanup) (graph_t * g);   /* function to deallocate layout-specific data */


	
	
	
	
	
	


	/* to have subgraphs */
	int n_cluster;
	graph_t **clust;	/* clusters are in clust[1..n_cluster] !!! */
	graph_t *dotroot;
	node_t *nlist;
	rank_t *rank;
	graph_t *parent;        /* containing cluster (not parent subgraph) */
	int level;		/* cluster nesting level (not node level!) */
	node_t	*minrep, *maxrep;	/* set leaders for min and max rank */

	/* fast graph node list */
	nlist_t comp;
	/* connected components */
	node_t *minset, *maxset;	/* set leaders */
	long n_nodes;
	/* includes virtual */
	short minrank, maxrank;

	/* various flags */
	boolean has_flat_edges;
	boolean has_sourcerank;
	boolean has_sinkrank;
	unsigned char	showboxes;
	fontname_kind fontnames;		/* to override mangling in SVG */

	int nodesep, ranksep;
	node_t *ln, *rn;	/* left, right nodes of bounding box */

	/* for clusters */
	node_t *leader, **rankleader;
	boolean expanded;
	char installed;
	char set_type;
	char label_pos;
	boolean exact_ranksep;


    } Agraphinfo_t;































































    typedef struct Agnodeinfo_t {
	Agrec_t hdr;
	shape_desc *shape;
	void *shape_info;
	pointf coord;
	double width, height;  /* inches */
	boxf bb;
	double ht, lw, rw;
	textlabel_t *label;
	textlabel_t *xlabel;
	void *alg;
	char state;
	unsigned char gui_state; /* Node state for GUI ops */
	boolean clustnode;


	
	
	


	unsigned char showboxes;
	boolean  has_port;
	node_t* rep;
	node_t *set;

	/* fast graph */
	char node_type, mark, onstack;
	char ranktype, weight_class;
	node_t *next, *prev;
	elist in, out, flat_out, flat_in, other;
	graph_t *clust;

	/* for union-find and collapsing nodes */
	int UF_size;
	node_t *UF_parent;
	node_t *inleaf, *outleaf;

	/* for placing nodes */
	int rank, order;	/* initially, order = 1 for ordered edges */
	double mval;
	elist save_in, save_out;

	/* for network-simplex */
	elist tree_in, tree_out;
	edge_t *par;
	int low, lim;
	int priority;

	double pad[1];


    } Agnodeinfo_t;


























































    typedef struct Agedgeinfo_t {
	Agrec_t hdr;
	splines *spl;
	port tail_port, head_port;
	textlabel_t *label, *head_label, *tail_label, *xlabel;
	char edge_type;
	char adjacent;          /* true for flat edge with adjacent nodes */
	char label_ontop;
	unsigned char gui_state; /* Edge state for GUI ops */
	edge_t *to_orig;	/* for dot's shapes.c    */
	void *alg;


	
	
	


	unsigned char showboxes;
	boolean conc_opp_flag;
	short xpenalty;
	int weight;
	int cutvalue, tree_index;
	short count;
	unsigned short minlen;
	edge_t *to_virt;

    } Agedgeinfo_t;



































    typedef struct {
	int flags;
    } gvlayout_features_t;





#line 21 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\macros.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/





































#line 22 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\const.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/










/*	node,edge types */











/* collapsed node classifications */









/* type of cluster rank assignment */




/* default attributes */









































/* default margin for paged formats such as PostScript - in points  = 0.5in */

/* default margin for embedded formats such as PNG - in points */

/* default padding around graph - in points */








/* default polygon sample size for overlap removal and maps */


/* arrow types */


/* sides (e.g. of cluster margins) */





/* sides of boxes for SHAPE_path */








/* Obj types  for renderers */





/* output languages */



















/* for clusters */








/* edge types */







/* for graph server */



/* for neato */




/* drawing phases */



/* existence of labels */







/* type of graph label: GD_label_pos */





/* values specifying rankdir */





/* allowed charsets */




/* style flags (0-23)*/















/* shape (1-127) */


























/* fill types */





/* label types */




/* Flags stored in GD_flags 
 * Bit(s):  0     HAS_CLUST_EDGE
 *          1-3   ET_ 
 *          4     NEW_RANK
 */

/* edge types */








/* New ranking is used */

/******/

/* user-specified node position: ND_pinned */






/* fontsize at which text is omitted entirely */

/* fontsize at which text is rendered by a simple line */



#line 23 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\globals.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* this is to get the following win32 DLL junk to work.
 * if ever tempted to remove this, first please read:
 * http://joel.editthispage.com/stories/storyReader$47
 */



























/*visual studio*/





/*end visual studio*/












    extern char *Version;
    extern char **Files;	/* from command line */
    extern const char **Lib;		/* from command line */
    extern char *CmdName;
    extern char *specificFlags;
    extern char *specificItems;
    extern char *Gvfilepath;  /* Per-process path of files allowed in image attributes (also ps libs) */
    extern char *Gvimagepath; /* Per-graph path of files allowed in image attributes  (also ps libs) */

    extern unsigned char Verbose;
    extern unsigned char Reduce;
    extern int MemTest;
    extern char *HTTPServerEnVar;
    extern char *Output_file_name;
    extern int graphviz_errors;
    extern int Nop;
    extern double PSinputscale;
    extern int Syntax_errors;
    extern int Show_cnt;
    extern char** Show_boxes;	/* emit code for correct box coordinates */
    extern int CL_type;		/* NONE, LOCAL, GLOBAL */
    extern unsigned char Concentrate;	/* if parallel edges should be merged */
    extern double Epsilon;	/* defined in input_graph */
    extern int MaxIter;
    extern int Ndim;
    extern int State;		/* last finished phase */
    extern int EdgeLabelsDone;	/* true if edge labels have been positioned */
    extern double Initial_dist;
    extern double Damping;
    extern int Y_invert;	/* invert y in dot & plain output */
    extern int GvExitOnUsage;   /* gvParseArgs() should exit on usage or error */

    extern Agsym_t
	*G_activepencolor, *G_activefillcolor,
	*G_selectedpencolor, *G_selectedfillcolor,
	*G_visitedpencolor, *G_visitedfillcolor,
	*G_deletedpencolor, *G_deletedfillcolor,
	*G_ordering, *G_peripheries, *G_penwidth,
	*G_gradientangle, *G_margin;
    extern Agsym_t
	*N_height, *N_width, *N_shape, *N_color, *N_fillcolor,
	*N_activepencolor, *N_activefillcolor,
	*N_selectedpencolor, *N_selectedfillcolor,
	*N_visitedpencolor, *N_visitedfillcolor,
	*N_deletedpencolor, *N_deletedfillcolor,
	*N_fontsize, *N_fontname, *N_fontcolor, *N_margin,
	*N_label, *N_xlabel, *N_nojustify, *N_style, *N_showboxes,
	*N_sides, *N_peripheries, *N_ordering, *N_orientation,
	*N_skew, *N_distortion, *N_fixed, *N_imagescale, *N_layer,
	*N_group, *N_comment, *N_vertices, *N_z,
	*N_penwidth, *N_gradientangle;
    extern Agsym_t
	*E_weight, *E_minlen, *E_color, *E_fillcolor,
	*E_activepencolor, *E_activefillcolor,
	*E_selectedpencolor, *E_selectedfillcolor,
	*E_visitedpencolor, *E_visitedfillcolor,
	*E_deletedpencolor, *E_deletedfillcolor,
	*E_fontsize, *E_fontname, *E_fontcolor,
	*E_label, *E_xlabel, *E_dir, *E_style, *E_decorate,
	*E_showboxes, *E_arrowsz, *E_constr, *E_layer,
	*E_comment, *E_label_float,
	*E_samehead, *E_sametail,
	*E_arrowhead, *E_arrowtail,
	*E_headlabel, *E_taillabel,
	*E_labelfontsize, *E_labelfontname, *E_labelfontcolor,
	*E_labeldistance, *E_labelangle,
	*E_tailclip, *E_headclip,
	*E_penwidth;

    extern struct fdpParms_s* fdp_parms;











#line 24 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




#line 1 "graphviz-2.38.0\\lib\\common\\memory.h" 1






































    extern void *zmalloc(size_t);
    extern void *zrealloc(void *, size_t, size_t, size_t);
    extern void *gmalloc(size_t);
	extern void *grealloc(void *, size_t);







#line 25 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\colorprocs.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




#line 1 "graphviz-2.38.0\\lib\\common\\color.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




/* #include "arith.h" */





typedef struct hsvrgbacolor_t {
    char *name;
    unsigned char h, s, v;
    unsigned char r, g, b, a;
} hsvrgbacolor_t;

/* possible representations of color in gvcolor_t */
typedef enum { HSVA_DOUBLE, RGBA_BYTE, RGBA_WORD, CMYK_BYTE,
		RGBA_DOUBLE, COLOR_STRING, COLOR_INDEX } color_type_t;

/* gvcolor_t can hold a color spec in a choice or representations */
typedef struct color_s {
    union {
	double RGBA[4];
	double HSVA[4];
	unsigned char rgba[4];
	unsigned char cmyk[4];
	int rrggbbaa[4];
	char *string;
	int index;
    } u;
    color_type_t type;
} gvcolor_t;









#line 17 "graphviz-2.38.0\\lib\\common\\colorprocs.h" 2





extern void setColorScheme (char* s);
extern int colorxlate(char *str, gvcolor_t * color, color_type_t target_type);
extern char *canontoken(char *str);
extern int colorCvt(gvcolor_t *ocolor, gvcolor_t *ncolor);





#line 26 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\geomprocs.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* geometric functions (e.g. on points and boxes) with application to, but
 * no specific dependance on graphs */









#line 1 "graphviz-2.38.0\\lib\\common\\geom.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* geometric types and macros (e.g. points and boxes) with application to, but
 * no specific dependance on graphs */











    


































































#line 23 "graphviz-2.38.0\\lib\\common\\geomprocs.h" 2









extern box mkbox(point p, point q);
extern boxf mkboxf(pointf p, pointf q);

extern box flip_rec_box(box b, point p);
extern boxf flip_rec_boxf(boxf b, pointf p);

extern double ptToLine2 (pointf l1, pointf l2, pointf p);

extern int lineToBox(pointf p1, pointf p2, boxf b);

extern point ccwrotatep(point p, int ccwrot);
extern pointf ccwrotatepf(pointf p, int ccwrot);

extern point cwrotatep(point p, int cwrot);
extern pointf cwrotatepf(pointf p, int cwrot);

extern void rect2poly(pointf *p);

extern int line_intersect (pointf a, pointf b, pointf c, pointf d, pointf* p);






static inline point pointof(int x, int y)
{
    point r;

    r.x = x;
    r.y = y;
    return r;
}

static inline pointf pointfof(double x, double y)
{
    pointf r;

    r.x = x;
    r.y = y;
    return r;
}

static inline box boxof(int llx, int lly, int urx, int ury)
{
    box b;

    b.LL.x = llx, b.LL.y = lly;
    b.UR.x = urx, b.UR.y = ury;
    return b;
}

static inline boxf boxfof(double llx, double lly, double urx, double ury)
{
    boxf b;

    b.LL.x = llx, b.LL.y = lly;
    b.UR.x = urx, b.UR.y = ury;
    return b;
}

static inline point add_point(point p, point q)
{
    point r;

    r.x = p.x + q.x;
    r.y = p.y + q.y;
    return r;
}

static inline pointf add_pointf(pointf p, pointf q)
{
    pointf r;

    r.x = p.x + q.x;
    r.y = p.y + q.y;
    return r;
}

static inline point sub_point(point p, point q)
{
    point r;

    r.x = p.x - q.x;
    r.y = p.y - q.y;
    return r;
}

static inline pointf sub_pointf(pointf p, pointf q)
{
    pointf r;

    r.x = p.x - q.x;
    r.y = p.y - q.y;
    return r;
}

/* for +ve coord values, this rounds towards p */
static inline point mid_point(point p, point q)
{
    point r;

    r.x = (p.x + q.x) / 2;
    r.y = (p.y + q.y) / 2;
    return r;
}

static inline pointf mid_pointf(pointf p, pointf q)
{
    pointf r;

    r.x = (p.x + q.x) / 2.;
    r.y = (p.y + q.y) / 2.;
    return r;
}

static inline pointf interpolate_pointf(double t, pointf p, pointf q)
{
    pointf r; 

    r.x = p.x + t * (q.x - p.x);
    r.y = p.y + t * (q.y - p.y);
    return r;
}

static inline point exch_xy(point p)
{
    point r;

    r.x = p.y;
    r.y = p.x;
    return r;
}

static inline pointf exch_xyf(pointf p)
{
    pointf r;

    r.x = p.y;
    r.y = p.x;
    return r;
}

static inline box box_bb(box b0, box b1)
{
    box b;

    b.LL.x = ((b0.LL.x)<(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)<(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)>(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)>(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline boxf boxf_bb(boxf b0, boxf b1)
{
    boxf b;

    b.LL.x = ((b0.LL.x)<(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)<(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)>(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)>(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline box box_intersect(box b0, box b1)
{
    box b;

    b.LL.x = ((b0.LL.x)>(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)>(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)<(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)<(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline boxf boxf_intersect(boxf b0, boxf b1)
{
    boxf b;

    b.LL.x = ((b0.LL.x)>(b1.LL.x)?(b0.LL.x):(b1.LL.x));
    b.LL.y = ((b0.LL.y)>(b1.LL.y)?(b0.LL.y):(b1.LL.y));
    b.UR.x = ((b0.UR.x)<(b1.UR.x)?(b0.UR.x):(b1.UR.x));
    b.UR.y = ((b0.UR.y)<(b1.UR.y)?(b0.UR.y):(b1.UR.y));

    return b;
}

static inline int box_overlap(box b0, box b1)
{
    return (((b0).UR.x >= (b1).LL.x) && ((b1).UR.x >= (b0).LL.x) && ((b0).UR.y >= (b1).LL.y) && ((b1).UR.y >= (b0).LL.y));
}

static inline int boxf_overlap(boxf b0, boxf b1)
{
    return (((b0).UR.x >= (b1).LL.x) && ((b1).UR.x >= (b0).LL.x) && ((b0).UR.y >= (b1).LL.y) && ((b1).UR.y >= (b0).LL.y));
}

static inline int box_contains(box b0, box b1)
{
    return (((b0).UR.x >= (b1).UR.x) && ((b0).UR.y >= (b1).UR.y) && ((b0).LL.x <= (b1).LL.x) && ((b0).LL.y <= (b1).LL.y));
}

static inline int boxf_contains(boxf b0, boxf b1)
{
    return (((b0).UR.x >= (b1).UR.x) && ((b0).UR.y >= (b1).UR.y) && ((b0).LL.x <= (b1).LL.x) && ((b0).LL.y <= (b1).LL.y));
}

static inline pointf perp (pointf p)
{
    pointf r;

    r.x = -p.y;
    r.y = p.x;
    return r;
}

static inline pointf scale (double c, pointf p)
{
    pointf r;

    r.x = c * p.x;
    r.y = c * p.y;
    return r;
}










#line 27 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\cgraph\\agxbuf.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/








/* Extensible buffer:
 *  Malloc'ed memory is never released until agxbfree is called.
 */
    typedef struct {
	unsigned char *buf;	/* start of buffer */
	unsigned char *ptr;	/* next place to write */
	unsigned char *eptr;	/* end of buffer */
	int dyna;		/* true if buffer is malloc'ed */
    } agxbuf;

/* agxbinit:
 * Initializes new agxbuf; caller provides memory.
 * Assume if init is non-null, hint = sizeof(init[])
 */
    extern void agxbinit(agxbuf * xb, unsigned int hint,
			 unsigned char *init);

/* agxbput_n:
 * Append string s of length n into xb
 */
    extern int agxbput_n(agxbuf * xb, const char *s, unsigned int n);

/* agxbput:
 * Append string s into xb
 */
    extern int agxbput(agxbuf * xb, const char *s);

/* agxbfree:
 * Free any malloced resources.
 */
    extern void agxbfree(agxbuf * xb);

/* agxbpop:
 * Removes last character added, if any.
 */
    extern int agxbpop(agxbuf * xb);

/* agxbmore:
 * Expand buffer to hold at least ssz more bytes.
 */
    extern int agxbmore(agxbuf * xb, int unsigned ssz);

/* agxbputc:
 * Add character to buffer.
 *  int agxbputc(agxbuf*, char)
 */



/* agxbuse:
 * Null-terminates buffer; resets and returns pointer to data;
 *  char* agxbuse(agxbuf* xb)
 */


/* agxbstart:
 * Return pointer to beginning of buffer.
 *  char* agxbstart(agxbuf* xb)
 */


/* agxblen:
 * Return number of characters currently stored.
 *  int agxblen(agxbuf* xb)
 */


/* agxbclear:
 * Resets pointer to data;
 *  void agxbclear(agxbuf* xb)
 */


/* agxbnext:
 * Next position for writing.
 *  char* agxbnext(agxbuf* xb)
 */







#line 28 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\utils.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/









/*visual studio*/





/*end visual studio*/


    extern int strcasecmp(const char *s1, const char *s2);


    extern int strncasecmp(const char *s1, const char *s2, size_t n);


    extern nodequeue *new_queue(int);
    extern void free_queue(nodequeue *);
    extern void enqueue(nodequeue *, Agnode_t *);
    extern Agnode_t *dequeue(nodequeue *);
    extern pointf Bezier(pointf *, int, double, pointf *, pointf *);
    extern void attach_attrs(graph_t * g);
    extern void attach_attrs_and_arrows(graph_t*, int*, int*);
    extern char *xml_string(char *str);
    extern char *xml_string0(char *str, boolean raw);
    extern void write_plain(GVJ_t * job, graph_t * g, FILE * f, boolean extend);
    extern double yDir (double y);
    extern char *ps_string(char *s, int);
    extern char *strdup_and_subst_obj(char *str, void *obj);
    extern char *xml_url_string(char *s);
    extern void epsf_emit_body(GVJ_t *job, usershape_t *us);
    extern void epsf_define(GVJ_t * job);
    extern void undoClusterEdges(graph_t * g);
    extern Dt_t* mkClustMap (Agraph_t* g);
    extern Agraph_t* findCluster (Dt_t* map, char* name);
    extern attrsym_t* safe_dcl(graph_t * g, int obj_kind, char *name, char *def);

    extern int late_int(void *, Agsym_t *, int, int);
    extern double late_double(void *, Agsym_t *, double, double);
    extern char *late_nnstring(void *, Agsym_t *, char *);
    extern char *late_string(void *, Agsym_t *, char *);
    extern boolean late_bool(void *, Agsym_t *, int);
    extern double get_inputscale (graph_t* g);

    extern Agnode_t *UF_find(Agnode_t *);
    extern Agnode_t *UF_union(Agnode_t *, Agnode_t *);
    extern void UF_remove(Agnode_t *, Agnode_t *);
    extern void UF_singleton(Agnode_t *);
    extern void UF_setname(Agnode_t *, Agnode_t *);

    extern char *Fgets(FILE * fp);
    extern const char *safefile(const char *filename);

    extern boolean mapBool(char *, boolean);
    extern boolean mapbool(char *);
    extern int maptoken(char *, char **, int *);

    extern boolean findStopColor (char* colorlist, char* clrs[2], float* frac);
    extern int test_toggle(void);

    extern void common_init_node(node_t * n);
    extern int common_init_edge(edge_t * e);

    extern void updateBB(graph_t * g, textlabel_t * lp);
    extern void compute_bb(Agraph_t *);
    extern boxf polyBB (polygon_t* poly);
    extern boolean overlap_node(node_t *n, boxf b);
    extern boolean overlap_label(textlabel_t *lp, boxf b);
    extern boolean overlap_edge(edge_t *e, boxf b);

    extern void get_gradient_points(pointf * A, pointf * G, int n, float angle, int flags);

    extern int processClusterEdges(graph_t * g);

    extern char *latin1ToUTF8(char *);
    extern char *htmlEntityUTF8(char *, graph_t* g);
    extern char* utf8ToLatin1 (char* ins);
    extern char* scanEntity (char* t, agxbuf* xb);

    extern pointf dotneato_closest(splines * spl, pointf p);
    extern pointf neato_closest(splines * spl, pointf p);
    extern pointf spline_at_y(splines * spl, double y);

    extern Agsym_t *setAttr(graph_t*, void*, char*name, char *value, Agsym_t*);
    extern void setEdgeType (graph_t* g, int dflt);
    extern int edgeType (char* s, int dflt);
    extern int is_a_cluster (Agraph_t* g);

    /* from postproc.c */ 
    extern void gv_nodesize(Agnode_t * n, boolean flip);

    /* from timing.c */
    extern void start_timer(void);
    extern double elapsed_sec(void);

    /* from psusershape.c */
    extern void cat_libfile(GVJ_t * job, const char **arglib, const char **stdlib);

Agnodeinfo_t* ninf(Agnode_t* n);
Agraphinfo_t* ginf(Agraph_t* g);
Agedgeinfo_t* einf(Agedge_t* e);
    /**/

	









#line 29 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvplugin.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Header used by plugins */








#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcext.h" 1

/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Common header used by both clients and plugins */



















    
    			











    			







    
    
    

    
	
	
    

    















	


	












#line 21 "graphviz-2.38.0\\lib\\gvc\\gvplugin.h" 2

/* 
 * Terminology:
 *
 *    package         - e.g. libgvplugin_cairo.so
 *       api	      - e.g. render
 *          type      - e.g. "png", "ps"
 */

    typedef struct {
	int id;         /* an id that is only unique within a package 
			of plugins of the same api.
			A renderer-type such as "png" in the cairo package
			has an id that is different from the "ps" type
			in the same package */
	const char *type;	/* a string name, such as "png" or "ps" that
			distinguishes different types withing the same
			 (renderer in this case) */
	int quality;    /* an arbitrary integer used for ordering plugins of
			the same type from different packages */
	void *engine;   /* pointer to the jump table for the plugin */
	void *features; /* pointer to the feature description 
				void* because type varies by api */
    } gvplugin_installed_t;

    typedef struct {
	api_t api;
	gvplugin_installed_t *types;
    } gvplugin_api_t;

    typedef struct {
	char *packagename;    /* used when this plugin is builtin and has
					no pathname */
	gvplugin_api_t *apis;
    } gvplugin_library_t;





#line 30 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcjob.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Common header used by both clients and plugins */








#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcommon.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/








    typedef struct GVCOMMON_s {
	char **info;
	char *cmdname;
	int verbose;
	boolean config, auto_outfile_names;
        void (*errorfn) (const char *fmt, ...);
	const char **show_boxes; /* emit code for correct box coordinates */
	const char **lib; 

	/* rendering state */
	int viewNum;     /* current view - 1 based count of views,
			    all pages in all layers */
	const lt_symlist_t *builtins;
	int demand_loading;
    } GVCOMMON_t;





#line 21 "graphviz-2.38.0\\lib\\gvc\\gvcjob.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\color.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/











    
    
    




		



    
	
	
	
	
	
	
	
    
    










#line 22 "graphviz-2.38.0\\lib\\gvc\\gvcjob.h" 2



    typedef struct gvdevice_engine_s gvdevice_engine_t;
    typedef struct gvformatter_engine_s gvformatter_engine_t;
    typedef struct gvrender_engine_s gvrender_engine_t;
    typedef struct gvlayout_engine_s gvlayout_engine_t;
    typedef struct gvtextlayout_engine_s gvtextlayout_engine_t;
    typedef struct gvloadimage_engine_s gvloadimage_engine_t;

    typedef enum { PEN_NONE, PEN_DASHED, PEN_DOTTED, PEN_SOLID } pen_type;
    typedef enum { FILL_NONE, FILL_SOLID, FILL_LINEAR, FILL_RADIAL } fill_type;
    typedef enum { FONT_REGULAR, FONT_BOLD, FONT_ITALIC } font_type;
    typedef enum { LABEL_PLAIN, LABEL_HTML } label_type;



    typedef enum { GVATTR_STRING, GVATTR_BOOL, GVATTR_COLOR } gvattr_t;

/* The -T output formats listed below are examples only, they are not definitive or inclusive,
 other outputs may use the flags now, or in the future 

                   Default emit order is breadth first graph walk order 
 EMIT_SORTED			emits nodes before edges		
 EMIT_COLORS			emits colors before nodes or edge -Tfig 
 EMIT_CLUSTERS_LAST		emits cluster after nodes and edges 	
 EMIT_PREORDER			emit in preorder traversal ???		
 EMIT_EDGE_SORTED		emits edges before nodes		

 GVDEVICE_DOES_PAGES		provides pagination support -Tps	
 GVDEVICE_DOES_LAYERS		provides support for layers -Tps	
 GVDEVICE_EVENTS		supports mouse events -Tgtk, -Txlib	
 GVDEVICE_DOES_TRUECOLOR	supports alpha channel -Tpng, -Tgtk, -Txlib 
 GVDEVICE_BINARY_FORMAT		Suppresses \r\n substitution for linends 
 GVDEVICE_COMPRESSED_FORMAT	controls libz compression		
 GVDEVICE_NO_WRITER		used when gvdevice is not used because device uses its own writer, -Tming, devil outputs   (FIXME seems to overlap OUTPUT_NOT_REQUIRED)

 GVRENDER_Y_GOES_DOWN		device origin top left, y goes down, otherwise
  				device origin lower left, y goes up	
 GVRENDER_DOES_TRANSFORM	device uses scale, translate, rotate to do its own
 				coordinate transformations, otherwise coordinates 
  				are pre-transformed			
 GVRENDER_DOES_ARROWS		renderer has its own idea of arrow shapes (deprecated) 
 GVRENDER_DOES_LABELS		basically, maps don't need labels	
 GVRENDER_DOES_MAPS		renderer encodes mapping information for mouse events -Tcmapx -Tsvg 
 GVRENDER_DOES_MAP_RECTANGLE	supports a 2 coord rectngle optimization 
 GVRENDER_DOES_MAP_CIRCLE	supports a 1 coord + radius circle optimization	
 GVRENDER_DOES_MAP_POLYGON	supports polygons (basically, -Tsvg uses anchors, so doesn't need to support any map shapes) 
 GVRENDER_DOES_MAP_ELLIPSE	supports a 2 coord ellipse optimization	
 GVRENDER_DOES_MAP_BSPLINE	supports mapping of splines		
 GVRENDER_DOES_TOOLTIPS		can represent tooltip info -Tcmapx, -Tsvg		
 GVRENDER_DOES_TARGETS		can represent target info (open link in a new tab or window) 
 GVRENDER_DOES_Z		render support 2.5D representation -Tvrml 
 GVRENDER_NO_WHITE_BG		don't paint white background, assumes white paper -Tps 
 LAYOUT_NOT_REQUIRED 		don't perform layout -Tcanon 		
 OUTPUT_NOT_REQUIRED		don't use gvdevice for output (basically when agwrite() used instead) -Tcanon, -Txdot 
 */































    typedef struct {
	int flags;
	double default_pad;	/* graph units */
	char **knowncolors;
	int sz_knowncolors;
	color_type_t color_type;
    } gvrender_features_t;

    typedef struct {
	int flags;
	pointf default_margin;  /* left/right, top/bottom - points */
	pointf default_pagesize;/* default page width, height - points */
	pointf default_dpi;
    } gvdevice_features_t;



    typedef struct gvplugin_active_device_s {
        gvdevice_engine_t *engine;
        int id;
        gvdevice_features_t *features;
        const char *type;
    } gvplugin_active_device_t;

    typedef struct gvplugin_active_render_s {
        gvrender_engine_t *engine;
        int id;
        gvrender_features_t *features;
        const char *type;
    } gvplugin_active_render_t;

    typedef struct gvplugin_active_loadimage_t {
	gvloadimage_engine_t *engine;
	int id;
	const char *type;
    } gvplugin_active_loadimage_t;

    typedef struct gv_argvlist_s {
	char **argv;
	int argc;
	int alloc;
    } gv_argvlist_t;
    
    typedef struct gvdevice_callbacks_s {
	void (*refresh) (GVJ_t * job);
        void (*button_press) (GVJ_t * job, int button, pointf pointer);
        void (*button_release) (GVJ_t * job, int button, pointf pointer);
        void (*motion) (GVJ_t * job, pointf pointer);
        void (*modify) (GVJ_t * job, const char *name, const char *value);
        void (*del) (GVJ_t * job);  /* can't use "delete" 'cos C++ stole it */
        void (*read) (GVJ_t * job, const char *filename, const char *layout);
        void (*layout) (GVJ_t * job, const char *layout);
        void (*render) (GVJ_t * job, const char *format, const char *filename);
    } gvdevice_callbacks_t;

    typedef int (*gvevent_key_callback_t) (GVJ_t * job);

    typedef struct gvevent_key_binding_s {
	char *keystring;
	gvevent_key_callback_t callback;
    } gvevent_key_binding_t;

    typedef enum {MAP_RECTANGLE, MAP_CIRCLE, MAP_POLYGON, } map_shape_t;

    typedef enum {ROOTGRAPH_OBJTYPE, CLUSTER_OBJTYPE, NODE_OBJTYPE, EDGE_OBJTYPE} obj_type;

    /* If this enum is changed, the implementation of xbuf and xbufs in
     * gvrender_core_dot.c will probably need to be changed.
     */
    typedef enum {
	EMIT_GDRAW, EMIT_CDRAW, EMIT_TDRAW, EMIT_HDRAW, 
	EMIT_GLABEL, EMIT_CLABEL, EMIT_TLABEL, EMIT_HLABEL, 
	EMIT_NDRAW, EMIT_EDRAW, EMIT_NLABEL, EMIT_ELABEL,
    } emit_state_t;

    typedef struct obj_state_s obj_state_t;

    struct obj_state_s {
	obj_state_t *parent;

	obj_type type;
	union {
	    graph_t *g;
	    graph_t *sg;  
	    node_t *n;
	    edge_t *e;
	} u;

	emit_state_t emit_state; 

	gvcolor_t pencolor, fillcolor, stopcolor;
	int gradient_angle;
	float gradient_frac;
	pen_type pen;
	fill_type fill;
	double penwidth;
	char **rawstyle;

	double z, tail_z, head_z;   /* z depths for 2.5D renderers such as vrml */

	/* fully substituted text strings */
	char *label;
	char *xlabel;
	char *taillabel;
	char *headlabel; 

	char *url;              /* if GVRENDER_DOES_MAPS */
	char *id;
	char *labelurl;
	char *tailurl;
	char *headurl; 

	char *tooltip;          /* if GVRENDER_DOES_TOOLTIPS */
	char *labeltooltip;
	char *tailtooltip;
	char *headtooltip; 

	char *target;           /* if GVRENDER_DOES_TARGETS */
	char *labeltarget;
	char *tailtarget;
	char *headtarget; 

	int explicit_tooltip:1;
	int explicit_tailtooltip:1;
	int explicit_headtooltip:1;
	int explicit_labeltooltip:1;
	int explicit_tailtarget:1;
	int explicit_headtarget:1;
	int explicit_edgetarget:1;
	int explicit_tailurl:1;
	int explicit_headurl:1;

	/* primary mapped region - node shape, edge labels */
	map_shape_t url_map_shape; 
	int url_map_n;                  /* number of points for url map if GVRENDER_DOES_MAPS */
	pointf *url_map_p;

	/* additonal mapped regions for edges */
	int url_bsplinemap_poly_n;      /* number of polygons in url bspline map
					 if GVRENDER_DOES_MAPS && GVRENDER_DOES_MAP_BSPLINES */
	int *url_bsplinemap_n;          /* array of url_bsplinemap_poly_n ints 
					 of number of points in each polygon */
	pointf *url_bsplinemap_p;       /* all the polygon points */

	int tailendurl_map_n;           /* tail end intersection with node */
	pointf *tailendurl_map_p;

	int headendurl_map_n;           /* head end intersection with node */
	pointf *headendurl_map_p;
    };

/* Note on units:
 *     points  - a physical distance (1/72 inch) unaffected by zoom or dpi.
 *     graph units - related to physical distance by zoom.  Equals points at zoom=1
 *     device units - related to physical distance in points by dpi/72
 */

    struct GVJ_s {
	GVC_t *gvc;		/* parent gvc */
	GVJ_t *next;		/* linked list of jobs */
	GVJ_t *next_active;	/* linked list of active jobs (e.g. multiple windows) */

	GVCOMMON_t *common;

	obj_state_t *obj;	/* objects can be nested (at least clusters can)
					so keep object state on a stack */
	char *input_filename;
	int graph_index;

	const char *layout_type;

	const char *output_filename;
	FILE *output_file;
	char *output_data;
	unsigned int output_data_allocated;
	unsigned int output_data_position;

	const char *output_langname;
	int output_lang;

	gvplugin_active_render_t render;
	gvplugin_active_device_t device;
	gvplugin_active_loadimage_t loadimage;
	gvdevice_callbacks_t *callbacks;
	pointf device_dpi;
	boolean device_sets_dpi;

	void *display;
	int screen;

	void *context;		/* gd or cairo surface */
	boolean external_context;	/* context belongs to caller */
	char *imagedata;	/* location of imagedata */

        int flags;		/* emit_graph flags */

	int numLayers;		/* number of layers */
	int layerNum;		/* current layer - 1 based*/

	point 	pagesArraySize; /* 2D size of page array */
	point	pagesArrayFirst;/* 2D starting corner in */
	point	pagesArrayMajor;/* 2D major increment */
	point	pagesArrayMinor;/* 2D minor increment */
	point	pagesArrayElem; /* 2D coord of current page - 0,0 based */
        int	numPages;	/* number of pages */

	boxf    bb;		/* graph bb with padding - graph units */
	pointf  pad;		/* padding around bb - graph units */
	boxf    clip;		/* clip region in graph units */
	boxf	pageBox;	/* current page in graph units */
	pointf	pageSize;	/* page size in graph units */
	pointf  focus;		/* viewport focus - graph units */

	double  zoom;		/* viewport zoom factor (points per graph unit) */
	int	rotation;	/* viewport rotation (degrees)  0=portrait, 90=landscape */

	pointf  view;		/* viewport size - points */
	boxf	canvasBox;	/* viewport area - points */
        pointf  margin;		/* job-specific margin - points */

	pointf	dpi;		/* device resolution device-units-per-inch */

        unsigned int width;     /* device width - device units */
        unsigned int height;    /* device height - device units */
	box     pageBoundingBox;/* rotated boundingBox - device units */
	box     boundingBox;    /* cumulative boundingBox over all pages - device units */

	pointf  scale;		/* composite device to graph units (zoom and dpi) */
	pointf  translation;    /* composite translation */
	pointf  devscale;	/* composite device to points: dpi, y_goes_down */

	boolean	fit_mode,
		needs_refresh,
		click,
		has_grown,
		has_been_rendered;

	unsigned char button;   /* active button */
	pointf pointer;		/* pointer position in device units */
	pointf oldpointer;	/* old pointer position in device units */

	void *current_obj;      /* graph object that pointer is in currently */

	void *selected_obj;      /* graph object that has been selected */
					/* (e.g. button 1 clicked on current obj) */
	char *active_tooltip;		/* tooltip of active object - or NULL */
	char *selected_href;		/* href of selected object - or NULL */
	gv_argvlist_t selected_obj_type_name; /* (e.g. "edge" "node3" "e" "->" "node5" "") */
	gv_argvlist_t selected_obj_attributes; /* attribute triplets: name, value, type */
				/* e.g. "color", "red", GVATTR_COLOR,
					"style", "filled", GVATTR_BOOL, */

	void *window;		/* display-specific data for gvrender plugin */

        /* keybindings for keyboard events */
	gvevent_key_binding_t *keybindings;
	int numkeys;
	void *keycodes;
    };





#line 31 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* Common header used by both clients and plugins */








#line 1 "graphviz-2.38.0\\lib\\cdt\\cdt.h" 1




























































	
	
	  
	





	





	





	
	
	
	  
	
	
	
	
	
				





	
	
	
	
	
	
	
	

















	
	
	
	
	
	
	
	
	





	
	
	
	























































































































































































#line 21 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcommon.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/








    
	
	
	
	
        
	
	

	
	
	
	
    





#line 22 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 2
#line 1 "graphviz-2.38.0\\lib\\common\\color.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/











    
    
    




		



    
	
	
	
	
	
	
	
    
    










#line 23 "graphviz-2.38.0\\lib\\gvc\\gvcint.h" 2

    /* active plugin headers */
    typedef struct gvplugin_active_layout_s {
        gvlayout_engine_t *engine;
        int id;
        gvlayout_features_t *features;
        const char *type;
    } gvplugin_active_layout_t;

    typedef struct gvplugin_active_textlayout_s {
        gvtextlayout_engine_t *engine;
        int id;
        char *type;
    } gvplugin_active_textlayout_t;

    typedef struct gvplugin_package_s gvplugin_package_t;

    struct gvplugin_package_s {
        gvplugin_package_t *next;
        char *path;
        char *name;
    };

    struct gvplugin_available_s {
	gvplugin_available_t *next;     /* next plugin in linked list, or NULL */
	const char *typestr;		/* type string, e.g. "png" or "ps" */
	int quality;			/* Programmer assigned quality ranking within type (+ve or -ve int).
					First implementation of type should be given "0" quality */
	gvplugin_package_t *package;	/* details of library containing plugin */
	gvplugin_installed_t *typeptr;  /* pointer to jumptable for plugin,
					or NULL if not yet loaded */
    };

    struct GVG_s {
	GVC_t *gvc;	/* parent gvc */
	GVG_t *next;	/* next gvg in list */

	char *input_filename; /* or NULL if stdin */
	int graph_index;  /* index of graph within input_file */
	graph_t *g;
    };



    struct GVC_s {
	GVCOMMON_t common;

	char *config_path;
	boolean config_found;

	/* gvParseArgs */
	char **input_filenames; /* null terminated array of input filenames */

	/* gvNextInputGraph() */
	GVG_t *gvgs;	/* linked list of graphs */
	GVG_t *gvg;	/* current graph */

	/* plugins */

	/* APIS expands to "+1 +1 ... +1" to give the number of APIs */
	gvplugin_available_t *apis[ +1 +1 +1 +1 +1 ]; /* array of linked-list of plugins per api */
	gvplugin_available_t *api[ +1 +1 +1 +1 +1 ];  /* array of current plugins per api */

	gvplugin_package_t *packages;   /* list of available packages */

        /* externally provided write() displine */
	size_t (*write_fn) (GVJ_t *job, const char *s, size_t len);

	/* fonts and textlayout */
	Dtdisc_t textfont_disc;
	Dt_t *textfont_dt;
	gvplugin_active_textlayout_t textlayout; /* always use best avail for all jobs */
//	void (*free_layout) (void *layout);   /* function for freeing layouts (mostly used by pango) */
	
/* FIXME - everything below should probably move to GVG_t */

	/* gvrender_config() */
	GVJ_t *jobs;	/* linked list of jobs */
	GVJ_t *job;	/* current job */

	graph_t *g;      /* current graph */

	/* gvrender_begin_job() */
	gvplugin_active_layout_t layout;

	char *graphname;	/* name from graph */
	GVJ_t *active_jobs;   /* linked list of active jobs */

	/* pagination */
	char *pagedir;		/* pagination order */
	pointf margin;		/* margins in graph units */
	pointf pad;		/* pad in graph units */
	pointf pageSize;	/* pageSize in graph units, not including margins */
	point pb;		/* page size - including margins (inches) */
	boxf bb;		/* graph bb in graph units, not including margins */
	int rotation;		/* rotation - 0 = portrait, 90 = landscape */
	boolean graph_sets_pad, graph_sets_margin, graph_sets_pageSize, graph_sets_rotation;

	/* layers */
	char *layerDelims;	/* delimiters in layer names */
	char *layerListDelims;	/* delimiters between layer ranges */ 
	char *layers;		/* null delimited list of layer names */
	char **layerIDs;	/* array of layer names */
	int numLayers;		/* number of layers */
	int *layerlist;

	/* default font */
	char *defaultfontname;
	double defaultfontsize;

	/* default line style */
	char **defaultlinestyle;

	/* render defaults set from graph */
	gvcolor_t bgcolor;	/* background color */

	/* whether to mangle font names (at least in SVG), usually false */
	int fontrenaming;
    };











#line 32 "graphviz-2.38.0\\lib\\common\\render.h" 2
#line 1 "graphviz-2.38.0\\lib\\gvc\\gvcproc.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/

/* This is the public header for the callers of libgvc */






/* these are intended to be private entry points - see gvc.h for the public ones */

/* configuration */

     char *gvconfig_libdir(GVC_t * gvc);
     void gvconfig(GVC_t * gvc, boolean rescan);
     char *gvhostname(void);

/* plugins */

     boolean gvplugin_install(GVC_t * gvc, api_t api,
		    const char *typestr, int quality, gvplugin_package_t *package,
		    gvplugin_installed_t * typeptr);
     gvplugin_available_t *gvplugin_load(GVC_t * gvc, api_t api, const char *type);
     gvplugin_library_t *gvplugin_library_load(GVC_t *gvc, char *path);
     api_t gvplugin_api(char *str);
     char * gvplugin_api_name(api_t api);
     void gvplugin_write_status(GVC_t * gvc);
     char *gvplugin_list(GVC_t * gvc, api_t api, const char *str);

     Agraph_t * gvplugin_graph(GVC_t * gvc);

/* job */

     void gvjobs_output_filename(GVC_t * gvc, const char *name);
     boolean gvjobs_output_langname(GVC_t * gvc, const char *name);
     GVJ_t *gvjobs_first(GVC_t * gvc);
     GVJ_t *gvjobs_next(GVC_t * gvc);
     void gvjobs_delete(GVC_t * gvc);

/* emit */
     void gvemit_graph(GVC_t * gvc, graph_t * g);

/* textlayout */

     int gvtextlayout_select(GVC_t * gvc);
     boolean gvtextlayout(GVC_t *gvc, textspan_t *span, char **fontpath);

/* loadimage */
     void gvloadimage(GVJ_t *job, usershape_t *us, boxf b, boolean filled, const char *target);
    
/* usershapes */
     point gvusershape_size_dpi(usershape_t *us, pointf dpi);
     point gvusershape_size(graph_t *g, char *name);
     usershape_t *gvusershape_find(char *name);

/* device */
     int gvdevice_initialize(GVJ_t * job);
     void gvdevice_format(GVJ_t * job);
     void gvdevice_finalize(GVJ_t * job);

/* render */

     pointf gvrender_ptf(GVJ_t *job, pointf p);
     pointf* gvrender_ptf_A(GVJ_t *job, pointf *af, pointf *AF, int n);

     int gvrender_begin_job(GVJ_t * job);
     void gvrender_end_job(GVJ_t * job);
     int gvrender_select(GVJ_t * job, const char *lang);
     int gvrender_features(GVJ_t * job);
     void gvrender_begin_graph(GVJ_t * job, graph_t * g);
     void gvrender_end_graph(GVJ_t * job);
     void gvrender_begin_page(GVJ_t * job);
     void gvrender_end_page(GVJ_t * job);
     void gvrender_begin_layer(GVJ_t * job);
     void gvrender_end_layer(GVJ_t * job);
     void gvrender_begin_cluster(GVJ_t * job, graph_t * sg);
     void gvrender_end_cluster(GVJ_t * job, graph_t *g);
     void gvrender_begin_nodes(GVJ_t * job);
     void gvrender_end_nodes(GVJ_t * job);
     void gvrender_begin_edges(GVJ_t * job);
     void gvrender_end_edges(GVJ_t * job);
     void gvrender_begin_node(GVJ_t * job, node_t * n);
     void gvrender_end_node(GVJ_t * job);
     void gvrender_begin_edge(GVJ_t * job, edge_t * e);
     void gvrender_end_edge(GVJ_t * job);
     void gvrender_begin_anchor(GVJ_t * job,
		char *href, char *tooltip, char *target, char *id);
     void gvrender_end_anchor(GVJ_t * job);
     void gvrender_begin_label(GVJ_t * job, label_type type);
     void gvrender_end_label(GVJ_t * job);
     void gvrender_textspan(GVJ_t * job, pointf p, textspan_t * span);
     void gvrender_set_pencolor(GVJ_t * job, char *name);
     void gvrender_set_penwidth(GVJ_t * job, double penwidth);
     void gvrender_set_fillcolor(GVJ_t * job, char *name);
     void gvrender_set_gradient_vals (GVJ_t * job, char *stopcolor, int angle, float frac);

     void gvrender_set_style(GVJ_t * job, char **s);
     void gvrender_ellipse(GVJ_t * job, pointf * AF, int n, int filled);
     void gvrender_polygon(GVJ_t* job, pointf* af, int n, int filled);
     void gvrender_box(GVJ_t * job, boxf BF, int filled);
     void gvrender_beziercurve(GVJ_t * job, pointf * AF, int n,
			int arrow_at_start, int arrow_at_end, boolean filled);
     void gvrender_polyline(GVJ_t * job, pointf * AF, int n);
     void gvrender_comment(GVJ_t * job, char *str);
     void gvrender_usershape(GVJ_t * job, char *name, pointf * AF, int n, boolean filled, char *imagescale);

/* layout */

     int gvlayout_select(GVC_t * gvc, const char *str);
     int gvFreeLayout(GVC_t * gvc, Agraph_t * g);
     int gvLayoutJobs(GVC_t * gvc, Agraph_t * g);

/* argvlist */
     gv_argvlist_t *gvNEWargvlist(void);
     void gv_argvlist_set_item(gv_argvlist_t *list, int index, char *item);
     void gv_argvlist_reset(gv_argvlist_t *list);
     void gv_argvlist_free(gv_argvlist_t *list);




#line 33 "graphviz-2.38.0\\lib\\common\\render.h" 2

    typedef struct epsf_s {
	int macro_id;
	point offset;
    } epsf_t;

    typedef void (*nodesizefn_t) (Agnode_t *, boolean);

/*visual studio*/





/*end visual studio*/

	extern void add_box(path *, boxf);
    extern void arrow_flags(Agedge_t * e, int *sflag, int *eflag);
    extern boxf arrow_bb(pointf p, pointf u, double arrowsize, int flag);
    extern void arrow_gen(GVJ_t * job, emit_state_t emit_state, pointf p, pointf u,
			  double arrowsize, double penwidth, int flag);
    extern double arrow_length(edge_t * e, int flag);
    extern int arrowEndClip(edge_t*, pointf*, int, int , bezier*, int eflag);
    extern int arrowStartClip(edge_t*, pointf* ps, int, int, bezier*, int sflag);
    extern void arrowOrthoClip(edge_t*, pointf* ps, int, int, bezier*, int sflag, int eflag);
    extern void beginpath(path *, Agedge_t *, int, pathend_t *, boolean);
    extern void bezier_clip(inside_t * inside_context,
			    boolean(*insidefn) (inside_t * inside_context,
						pointf p), pointf * sp,
			    boolean left_inside);
    extern shape_desc *bind_shape(char *name, node_t *);
    extern void makeStraightEdge(graph_t * g, edge_t * e, int edgetype, splineInfo * info);
    extern void makeStraightEdges(graph_t* g, edge_t** edges, int e_cnt, int et, splineInfo* sinfo);
    extern void clip_and_install(edge_t * fe, node_t * hn,
	pointf * ps, int pn, splineInfo * info);
    extern char* charsetToStr (int c);
    extern pointf coord(node_t * n);
    extern void do_graph_label(graph_t * sg);
    extern void graph_init(graph_t * g, boolean use_rankdir);
    extern void graph_cleanup(graph_t * g);
    extern int dotneato_args_initialize(GVC_t * gvc, int, char **);
    extern int dotneato_usage(int);
    extern void dotneato_postprocess(Agraph_t *);
    extern void gv_postprocess(Agraph_t *, int);
    extern void dotneato_set_margins(GVC_t * gvc, Agraph_t *);
    extern void dotneato_write(GVC_t * gvc, graph_t *g);
    extern void dotneato_write_one(GVC_t * gvc, graph_t *g);
    extern Ppolyline_t* ellipticWedge (pointf ctr, double major, double minor, double angle0, double angle1);
    extern void emit_clusters(GVJ_t * job, Agraph_t * g, int flags);
    extern char* getObjId (GVJ_t* job, void* obj, agxbuf* xb);
    /* extern void emit_begin_edge(GVJ_t * job, edge_t * e, char**); */
    /* extern void emit_end_edge(GVJ_t * job); */
    extern void emit_graph(GVJ_t * job, graph_t * g);
    extern void emit_label(GVJ_t * job, emit_state_t emit_state, textlabel_t *);
    extern int emit_once(char *message);
    extern void emit_jobs_eof(GVC_t * gvc);
    extern void emit_map_rect(GVJ_t *job, boxf b);
    extern void enqueue_neighbors(nodequeue *, Agnode_t *, int);
    extern void endpath(path *, Agedge_t *, int, pathend_t *, boolean);
    extern void epsf_init(node_t * n);
    extern void epsf_free(node_t * n);
    extern shape_desc *find_user_shape(const char *);
    extern void free_line(textspan_t *);
    extern void free_label(textlabel_t *);
    extern void free_textspan(textspan_t * tl, int);
    extern void getdouble(graph_t * g, char *name, double *result);
    extern splines *getsplinepoints(edge_t * e);
    extern void gv_fixLocale (int set);
    extern void gv_free_splines(edge_t * e);
    extern void gv_cleanup_edge(Agedge_t * e);
    extern void gv_cleanup_node(Agnode_t * n);
    extern void* init_xdot (Agraph_t* g);
    extern int initMapData (GVJ_t*, char*, char*, char*, char*, char*, void*);
    extern boolean isPolygon(node_t *);
    extern void makeSelfEdge(path * P, edge_t * edges[], int ind, int cnt,
	double sizex, double sizey, splineInfo * sinfo);
    extern textlabel_t *make_label(void *obj, char *str, int kind, double fontsize, char *fontname, char *fontcolor);
    extern bezier *new_spline(edge_t * e, int sz);
    extern char **parse_style(char *s);
    extern void place_graph_label(Agraph_t *);
    extern int place_portlabel(edge_t * e, boolean head_p);
    extern void makePortLabels(edge_t * e);
    extern pointf edgeMidpoint(graph_t* g, edge_t * e);
    extern void addEdgeLabels(graph_t* g, edge_t * e, pointf rp, pointf rq);
    extern void pop_obj_state(GVJ_t *job);
    extern obj_state_t* push_obj_state(GVJ_t *job);
    extern int rank(graph_t * g, int balance, int maxiter);
    extern port resolvePort(node_t*  n, node_t* other, port* oldport);
    extern void resolvePorts (edge_t* e);
    extern void round_corners(GVJ_t * job, pointf * AF, int sides, int style, int filled);
    extern int routesplinesinit(void);
    extern pointf *routesplines(path *, int *);
    extern void routesplinesterm(void);
    extern pointf* simpleSplineRoute (pointf, pointf, Ppoly_t, int*, int);
    extern pointf *routepolylines(path* pp, int* npoints);
    extern int selfRightSpace (edge_t* e);
    extern void setup_graph(GVC_t * gvc, graph_t * g);
    extern shape_kind shapeOf(node_t *);
    extern void shape_clip(node_t * n, pointf curve[4]);
    extern void make_simple_label (GVC_t * gvc, textlabel_t* rv);
    extern int stripedBox (GVJ_t * job, pointf* AF, char* clrs, int rotate);
    extern stroke_t* taper (bezier*, double (*radfunc_t)(double,double,double), double initwid, int linejoin, int linecap);
    extern stroke_t* taper0 (bezier* bez, double initwid);
    extern pointf textspan_size(GVC_t * gvc, textspan_t * span);
    extern Dt_t * textfont_dict_open(GVC_t *gvc);
    extern void textfont_dict_close(GVC_t *gvc);
    extern void translate_bb(Agraph_t *, int);
    extern int wedgedEllipse (GVJ_t* job, pointf * pf, char* clrs);
    extern void update_bb_bz(boxf *bb, pointf *cp);
    extern void write_attributed_dot(graph_t *g, FILE *f);
    extern void write_canonical_dot(graph_t *g, FILE *f);
    extern boxf xdotBB (graph_t* g);
    extern char *findAttrColor(void *obj, attrsym_t *colorattr, char *dflt);








#line 18 "graphviz-2.38.0\\lib\\dotgen\\dot.h" 2
#line 1 "graphviz-2.38.0\\lib\\dotgen\\dotprocs.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/





1			/* public data */

/* tabs at 8, or you're a sorry loser */




#line 1 "graphviz-2.38.0\\lib\\dotgen\\aspect.h" 1
/* $Id$Revision: */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/




typedef struct aspect_t {
    double targetAR;      /* target aspect ratio */
    double combiAR;
    int prevIterations;   /* no. of iterations in previous pass */
    int curIterations;    /* no. of iterations in current pass */
    int nextIter;         /* dynamically adjusted no. of iterations */
    int nPasses;          /* bound on no. of top-level passes */
    int badGraph;         /* hack: set if graph is disconnected or has
                           * clusters. If so, turn off aspect */
} aspect_t;

extern aspect_t* setAspect (Agraph_t * g, aspect_t* adata);
extern void rank3(graph_t * g, aspect_t * asp);
extern void initEdgeTypes(graph_t * g);
extern void init_UF_size(graph_t * g);
extern int countDummyNodes(graph_t * g);



#line 21 "graphviz-2.38.0\\lib\\dotgen\\dotprocs.h" 2

    extern void acyclic(Agraph_t *);
    extern void allocate_ranks(Agraph_t *);
    extern void build_ranks(Agraph_t *, int);
    extern void build_skeleton(Agraph_t *, Agraph_t *);
    extern void class1(Agraph_t *);
    extern void class2(Agraph_t *);
    extern void decompose(Agraph_t *, int);
    extern void delete_fast_edge(Agedge_t *);
    extern void delete_fast_node(Agraph_t *, Agnode_t *);
    extern void delete_flat_edge(Agedge_t *);
    extern void dot_cleanup(graph_t * g);
    extern void dot_layout(Agraph_t * g);
    extern void dot_init_node_edge(graph_t * g);
    extern void dot_scan_ranks(graph_t * g);
    extern void enqueue_neighbors(nodequeue * q, node_t * n0, int pass);
    extern void expand_cluster(Agraph_t *);
    extern Agedge_t *fast_edge(Agedge_t *);
    extern void fast_node(Agraph_t *, Agnode_t *);
    extern void fast_nodeapp(Agnode_t *, Agnode_t *);
    extern Agedge_t *find_fast_edge(Agnode_t *, Agnode_t *);
    extern Agedge_t *find_flat_edge(Agnode_t *, Agnode_t *);
    extern void flat_edge(Agraph_t *, Agedge_t *);
    extern int flat_edges(Agraph_t *);
    extern void install_cluster(Agraph_t *, Agnode_t *, int, nodequeue *);
    extern void install_in_rank(Agraph_t *, Agnode_t *);
    extern int is_cluster(Agraph_t *);
    extern void dot_compoundEdges(Agraph_t *);
    extern Agedge_t *make_aux_edge(Agnode_t *, Agnode_t *, double, int);
    extern void mark_clusters(Agraph_t *);
    extern void mark_lowclusters(Agraph_t *);
    extern int mergeable(edge_t * e, edge_t * f);
    extern void merge_chain(Agraph_t *, Agedge_t *, Agedge_t *, int);
    extern void merge_oneway(Agedge_t *, Agedge_t *);
    extern int ncross(Agraph_t *);
    extern Agedge_t *new_virtual_edge(Agnode_t *, Agnode_t *, Agedge_t *);
    extern int nonconstraint_edge(Agedge_t *);
    extern void other_edge(Agedge_t *);
    extern void rank1(graph_t * g);
    extern int portcmp(port p0, port p1);
    extern int ports_eq(edge_t *, edge_t *);
    extern void rec_reset_vlists(Agraph_t *);
    extern void rec_save_vlists(Agraph_t *);
    extern void reverse_edge(Agedge_t *);
    extern void safe_other_edge(Agedge_t *);
    extern void save_vlist(Agraph_t *);
    extern void unmerge_oneway(Agedge_t *);
    extern Agedge_t *virtual_edge(Agnode_t *, Agnode_t *, Agedge_t *);
    extern Agnode_t *virtual_node(Agraph_t *);
    extern void virtual_weight(Agedge_t *);
    extern void zapinlist(elist *, Agedge_t *);




    extern Agraph_t* dot_root(void *);
    extern void dot_concentrate(Agraph_t *);
    extern void dot_mincross(Agraph_t *, int);
    extern void dot_position(Agraph_t *, aspect_t*);
    extern void dot_rank(Agraph_t *, aspect_t*);
    extern void dot_sameports(Agraph_t *);
    extern void dot_splines(Agraph_t *);



     





#line 19 "graphviz-2.38.0\\lib\\dotgen\\dot.h" 2


#line 24 "graphviz-2.38.0\\lib\\dotgen\\mincross.c" 2

/* #define DEBUG */




static int gd_minrank(Agraph_t *g) {return (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank);}
static int gd_maxrank(Agraph_t *g) {return (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank);}
static rank_t *gd_rank(Agraph_t *g, int r) {return &(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r];}
static int nd_order(Agnode_t *v) { return (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order); }

	/* forward declarations */
static boolean medians(graph_t * g, int r0, int r1);
static int nodeposcmpf(node_t ** n0, node_t ** n1);
static int edgeidcmpf(edge_t ** e0, edge_t ** e1);
static void flat_breakcycles(graph_t * g);
static void flat_reorder(graph_t * g);
static void flat_search(graph_t * g, node_t * v);
static void init_mincross(graph_t * g);
static void merge2(graph_t * g);
static void init_mccomp(graph_t * g, int c);
static void cleanup2(graph_t * g, int nc);
static int mincross_clust(graph_t * par, graph_t * g, int);
static int mincross(graph_t * g, int startpass, int endpass, int);
static void mincross_step(graph_t * g, int pass);
static void mincross_options(graph_t * g);
static void save_best(graph_t * g);
static void restore_best(graph_t * g);
static adjmatrix_t *new_matrix(int i, int j);
static void free_matrix(adjmatrix_t * p);








	/* mincross parameters */
static int MinQuit;
static double Convergence;

static graph_t *Root;
static int GlobalMinRank, GlobalMaxRank;
static edge_t **TE_list;
static int *TI_list;
static boolean ReMincross;

/* dot_mincross:
 * Minimize edge crossings
 * Note that nodes are not placed into GD_rank(g) until mincross()
 * is called.
 */
void dot_mincross(graph_t * g, int doBalance)
{
    int c, nc;
    char *s;

    init_mincross(g);

    for (nc = c = 0; c < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size; c++) {
	init_mccomp(g, c);
	nc += mincross(g, 0, 2, doBalance);
    }

    merge2(g);

    /* run mincross on contents of each cluster */
    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++) {
	nc += mincross_clust(g, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c], doBalance);

	
	

    }

    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster) > 0)
	&& (!(s = agget(g, "remincross")) || (mapbool(s)))) {
	mark_lowclusters(g);
	ReMincross = (!(0));
	nc = mincross(g, 2, 2, doBalance);

	
	    

    }
    cleanup2(g, nc);
}

static adjmatrix_t *new_matrix(int i, int j)
{
    adjmatrix_t *rv = (adjmatrix_t*)zmalloc(sizeof(adjmatrix_t));
    rv->nrows = i;
    rv->ncols = j;
    rv->data = (char*)zmalloc((i * j)*sizeof(char));
    return rv;
}

static void free_matrix(adjmatrix_t * p)
{
    if (p) {
	free(p->data);
	free(p);
    }
}



static void init_mccomp(graph_t * g, int c)
{
    int r;

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list[c];
    if (c > 0) {
	for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n;
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n = 0;
	}
    }
}

static int betweenclust(edge_t * e)
{
    while ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig))
	e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig);
    return ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->clust) != (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->clust));
}

static void do_ordering_node (graph_t * g, node_t* n, int outflag)
{
    int i, ne;
    node_t *u, *v;
    edge_t *e, *f, *fe;
    edge_t **sortlist = TE_list;

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->clust))
	return;
    if (outflag) {
	for (i = ne = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[i]); i++)
	    if (!betweenclust(e))
		sortlist[ne++] = e;
    } else {
	for (i = ne = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[i]); i++)
	    if (!betweenclust(e))
		sortlist[ne++] = e;
    }
    if (ne <= 1)
	return;
    /* write null terminator at end of list.
       requires +1 in TE_list alloccation */
    sortlist[ne] = 0;
    qsort(sortlist, ne, sizeof(sortlist[0]), (qsort_cmpf) edgeidcmpf);
    for (ne = 1; (f = sortlist[ne]); ne++) {
	e = sortlist[ne - 1];
	if (outflag) {
	    u = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	    v = ((((((Agobj_t*)(f))->tag).objtype) == 2? (f): ((f)-1))->node);
	} else {
	    u = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	    v = ((((((Agobj_t*)(f))->tag).objtype) == 3? (f): ((f)+1))->node);
	}
	if (find_flat_edge(u, v))
	    return;
	fe = new_virtual_edge(u, v, NULL);
	(((Agedgeinfo_t*)(((Agobj_t*)(fe))->data))->edge_type) = 4;
	flat_edge(g, fe);
    }
}

static void do_ordering(graph_t * g, int outflag)
{
    /* Order all nodes in graph */
    node_t *n;

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	do_ordering_node (g, n, outflag);
    }
}

static void do_ordering_for_nodes(graph_t * g)
{
    /* Order nodes which have the "ordered" attribute */
    node_t *n;
    const char *ordering;

    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	if ((ordering = late_string(n, N_ordering, NULL))) {
	    if ((*(ordering)==*("out")&&!strcmp(ordering,"out")))
		do_ordering_node(g, n, (!(0)));
	    else if ((*(ordering)==*("in")&&!strcmp(ordering,"in")))
		do_ordering_node(g, n, 0);
	    else if (ordering[0])
		agerr(AGERR, "ordering '%s' not recognized for node '%s'.\n", ordering, agnameof(n));
	}
    }
}

/* ordered_edges:
 * handle case where graph specifies edge ordering
 * If the graph does not have an ordering attribute, we then
 * check for nodes having the attribute.
 * Note that, in this implementation, the value of G_ordering
 * dominates the value of N_ordering.
 */
static void ordered_edges(graph_t * g)
{
    char *ordering;

    if (!G_ordering && !N_ordering)
	return;
    if ((ordering = late_string(g, G_ordering, NULL))) {
	if ((*(ordering)==*("out")&&!strcmp(ordering,"out")))
	    do_ordering(g, (!(0)));
	else if ((*(ordering)==*("in")&&!strcmp(ordering,"in")))
	    do_ordering(g, 0);
	else if (ordering[0])
	    agerr(AGERR, "ordering '%s' not recognized.\n", ordering);
    }
    else
    {
	graph_t *subg;

	for (subg = agfstsubg(g); subg; subg = agnxtsubg(subg)) {
	    /* clusters are processed by separate calls to ordered_edges */
	    if (!is_cluster(subg))
		ordered_edges(subg);
	}
	if (N_ordering) do_ordering_for_nodes (g);
    }
}

static int mincross_clust(graph_t * par, graph_t * g, int doBalance)
{
    int c, nc;

    expand_cluster(g);
    ordered_edges(g);
    flat_breakcycles(g);
    flat_reorder(g);
    nc = mincross(g, 2, 2, doBalance);

    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	nc += mincross_clust(g, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c], doBalance);

    save_vlist(g);
    return nc;
}

static int left2right(graph_t * g, node_t * v, node_t * w)
{
    adjmatrix_t *M;
    int rv;

    /* CLUSTER indicates orig nodes of clusters, and vnodes of skeletons */
    if (ReMincross == 0) {
	if (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->clust) != (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->clust)) && ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->clust)) && ((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->clust))) {
	    /* the following allows cluster skeletons to be swapped */
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->ranktype) == 7)
		&& ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) == 1))
		return 0;
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->ranktype) == 7)
		&& ((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->node_type) == 1))
		return 0;
	    return (!(0));
	    /*return ((ND_ranktype(v) != CLUSTER) && (ND_ranktype(w) != CLUSTER)); */
	}
    } else {
	if (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->clust)) != ((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->clust)))
	    return (!(0));
    }
    M = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->rank)].flat;
    if (M == NULL)
	rv = 0;
    else {
	if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) {
	    node_t *t = v;
	    v = w;
	    w = t;
	}
	rv = (M->data[(((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->low))*M->ncols)+((((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->low))]);
    }
    return rv;
}

static int in_cross(node_t * v, node_t * w)
{
    register edge_t **e1, **e2;
    register int inv, cross = 0, t;

    for (e2 = (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->in).list; *e2; e2++) {
	register int cnt = (((Agedgeinfo_t*)(((Agobj_t*)(*e2))->data))->xpenalty);		
		
	inv = (((Agnodeinfo_t*)(((Agobj_t*)((((((((Agobj_t*)(*e2))->tag).objtype) == 3?(*e2):((*e2)+1))->node))))->data))->order);

	for (e1 = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->in).list; *e1; e1++) {
	    t = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(*e1))->tag).objtype) == 3?(*e1):((*e1)+1))->node)))->data))->order) - inv;
	    if ((t > 0)
		|| ((t == 0)
		    && (  (((Agedgeinfo_t*)(((Agobj_t*)(*e1))->data))->tail_port).p.x > (((Agedgeinfo_t*)(((Agobj_t*)(*e2))->data))->tail_port).p.x)))
		cross += (((Agedgeinfo_t*)(((Agobj_t*)(*e1))->data))->xpenalty) * cnt;
	}
    }
    return cross;
}

static int out_cross(node_t * v, node_t * w)
{
    register edge_t **e1, **e2;
    register int inv, cross = 0, t;

    for (e2 = (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->out).list; *e2; e2++) {
	register int cnt = (((Agedgeinfo_t*)(((Agobj_t*)(*e2))->data))->xpenalty);
	inv = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(*e2))->tag).objtype) == 2?(*e2):((*e2)-1))->node)))->data))->order);

	for (e1 = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).list; *e1; e1++) {
	    t = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(*e1))->tag).objtype) == 2?(*e1):((*e1)-1))->node)))->data))->order) - inv;
	    if ((t > 0)
		|| ((t == 0)
		    && (((((Agedgeinfo_t*)(((Agobj_t*)(*e1))->data))->head_port)).p.x > ((((Agedgeinfo_t*)(((Agobj_t*)(*e2))->data))->head_port)).p.x)))
		cross += (((((Agedgeinfo_t*)(((Agobj_t*)(*e1))->data))->xpenalty)) * cnt);
	}
    }
    return cross;

}

static void exchange(node_t * v, node_t * w)
{
    int vi, wi, r;

    r = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->rank);
    vi = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order);
    wi = (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->order);
    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) = wi;
    (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].v[wi] = v;
    (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->order) = vi;
    (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].v[vi] = w;
}

static void balanceNodes(graph_t * g, int r, node_t * v, node_t * w)
{
    node_t *s;			/* separator node */
    int sepIndex;
    int nullType;		/* type of null nodes */
    int cntDummy = 0, cntOri = 0;
    int k = 0, m = 0, k1 = 0, m1 = 0, i = 0;

    /* we only consider v and w of different types */
    if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) == (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->node_type))
	return;

    /* count the number of dummy and original nodes */
    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i]))->data))->node_type) == 0)
	    cntOri++;
	else
	    cntDummy++;
    }

    if (cntOri < cntDummy) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) == 0)
	    s = v;
	else
	    s = w;
    } else {
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) == 0)
	    s = w;
	else
	    s = v;
    }

    /* get the separator node index */
    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i] == s)
	    sepIndex = i;
    }

    nullType = ((((Agnodeinfo_t*)(((Agobj_t*)(s))->data))->node_type) == 0) ? 1 : 0;

    /* count the number of null nodes to the left and 
     * right of the separator node 
     */
    for (i = sepIndex - 1; i >= 0; i--) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i]))->data))->node_type) == nullType)
	    k++;
	else
	    break;
    }

    for (i = sepIndex + 1; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i]))->data))->node_type) == nullType)
	    m++;
	else
	    break;
    }

    /* now exchange v,w and calculate the same counts */

    exchange(v, w);

    /* get the separator node index */
    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i] == s)
	    sepIndex = i;
    }

    /* count the number of null nodes to the left and 
     * right of the separator node 
     */
    for (i = sepIndex - 1; i >= 0; i--) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i]))->data))->node_type) == nullType)
	    k1++;
	else
	    break;
    }

    for (i = sepIndex + 1; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i]))->data))->node_type) == nullType)
	    m1++;
	else
	    break;
    }

    if (abs(k1 - m1) > abs(k - m)) {
	exchange(v, w);		//revert to the original ordering
    }
}

static int balance(graph_t * g)
{
    int i, c0, c1, rv;
    node_t *v, *w;
    int r;

    rv = 0;

    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r >= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r--) {

	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].candidate = 0;
	for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n - 1; i++) {
	    v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
	    w = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i + 1];
	    assert((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) < (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->order));
	    if (left2right(g, v, w))
		continue;
	    c0 = c1 = 0;
	    if (r > 0) {
		c0 += in_cross(v, w);
		c1 += in_cross(w, v);
	    }

	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].n > 0) {
		c0 += out_cross(v, w);
		c1 += out_cross(w, v);
	    }

	    
		
		
		
		

		
		    
		    
		
		
		    
		    
		
	    


	    if (c1 <= c0) {
		balanceNodes(g, r, v, w);
	    }
	}
    }
    return rv;
}

static int transpose_step(graph_t * g, int r, int reverse)
{
    int i, c0, c1, rv;
    node_t *v, *w;

    rv = 0;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].candidate = 0;
    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n - 1; i++) {
	v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
	w = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i + 1];
	assert((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) < (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->order));
	if (left2right(g, v, w))
	    continue;
	c0 = c1 = 0;
	if (r > 0) {
	    c0 += in_cross(v, w);
	    c1 += in_cross(w, v);
	}
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].n > 0) {
	    c0 += out_cross(v, w);
	    c1 += out_cross(w, v);
	}
	if ((c1 < c0) || ((c0 > 0) && reverse && (c1 == c0))) {
	    exchange(v, w);
	    rv += (c0 - c1);
	    (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].valid = 0;
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].candidate = (!(0));

	    if (r > (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank)) {
		(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r - 1].valid = 0;
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r - 1].candidate = (!(0));
	    }
	    if (r < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank)) {
		(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r + 1].valid = 0;
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].candidate = (!(0));
	    }
	}
    }
    return rv;
}

static void transpose(graph_t * g, int reverse)
{
    int r, delta;

    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++)
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].candidate = (!(0));
    do {
	delta = 0;

	


	
	    
		

	for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].candidate) {
		delta += transpose_step(g, r, reverse);
	    }
	}
	/*} while (delta > ncross(g)*(1.0 - Convergence)); */
    } while (delta >= 1);
}

static int mincross(graph_t * g, int startpass, int endpass, int doBalance)
{
    int maxthispass, iter, trying, pass;
    int cur_cross, best_cross;

    if (startpass > 1) {
	cur_cross = best_cross = ncross(g);
	save_best(g);
    } else
	cur_cross = best_cross = ((int)(~(unsigned)0 >> 1));
    for (pass = startpass; pass <= endpass; pass++) {
	if (pass <= 1) {
	    maxthispass = ((4)<(MaxIter)?(4):(MaxIter));
	    if (g == dot_root(g))
		build_ranks(g, pass);
	    if (pass == 0)
		flat_breakcycles(g);
	    flat_reorder(g);

	    if ((cur_cross = ncross(g)) <= best_cross) {
		save_best(g);
		best_cross = cur_cross;
	    }
	    trying = 0;
	} else {
	    maxthispass = MaxIter;
	    if (cur_cross > best_cross)
		restore_best(g);
	    cur_cross = best_cross;
	}
	trying = 0;
	for (iter = 0; iter < maxthispass; iter++) {
	    if (Verbose)
		fprintf(stderr,
			"mincross: pass %d iter %d trying %d cur_cross %d best_cross %d\n",
			pass, iter, trying, cur_cross, best_cross);
	    if (trying++ >= MinQuit)
		break;
	    if (cur_cross == 0)
		break;
	    mincross_step(g, iter);
	    if ((cur_cross = ncross(g)) <= best_cross) {
		save_best(g);
		if (cur_cross < Convergence * best_cross)
		    trying = 0;
		best_cross = cur_cross;
	    }
	}
	if (cur_cross == 0)
	    break;
    }
    if (cur_cross > best_cross)
	restore_best(g);
    if (best_cross > 0) {
	transpose(g, 0);
	best_cross = ncross(g);
    }
    if (doBalance) {
	for (iter = 0; iter < maxthispass; iter++)
	    balance(g);
    }

    return best_cross;
}

static void restore_best(graph_t * g)
{
    node_t *n;
    int r;

    for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next))
	(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order) = ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord)).x;
    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].valid = 0;
	qsort((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n, sizeof((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[0].v[0]),
	      (qsort_cmpf) nodeposcmpf);
    }
}

static void save_best(graph_t * g)
{
    node_t *n;
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next))
	((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->coord)).x = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order);
}

/* merges the connected components of g */
static void merge_components(graph_t * g)
{
    int c;
    node_t *u, *v;

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size <= 1)
	return;
    u = NULL;
    for (c = 0; c < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size; c++) {
	v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list[c];
	if (u)
	    (((Agnodeinfo_t*)(((Agobj_t*)(u))->data))->next) = v;
	(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->prev) = u;
	while ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->next)) {
	    v = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->next);
	}
	u = v;
    }
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).size = 1;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist) = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->comp).list[0];
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) = GlobalMinRank;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) = GlobalMaxRank;
}

/* merge connected components, create globally consistent rank lists */
static void merge2(graph_t * g)
{
    int i, r;
    node_t *v;

    /* merge the components and rank limits */
    merge_components(g);

    /* install complete ranks */
    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].an;
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].av;
	for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	    v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
	    if (v == NULL) {
		if (Verbose)
		    fprintf(stderr,
			    "merge2: graph %s, rank %d has only %d < %d nodes\n",
			    agnameof(g), r, i, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n);
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n = i;
		break;
	    }
	    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) = i;
	}
    }
}

static void cleanup2(graph_t * g, int nc)
{
    int i, j, r, c;
    node_t *v;
    edge_t *e;

    if (TI_list) {
	free(TI_list);
	TI_list = NULL;
    }
    if (TE_list) {
	free(TE_list);
	TE_list = NULL;
    }
    /* fix vlists of clusters */
    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	rec_reset_vlists((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c]);

    /* remove node temporary edges for ordering nodes */
    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	    v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
	    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) = i;
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list) {
		for (j = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list[j]); j++)
		    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) == 4) {
			delete_flat_edge(e);
			free(e->base.data);
			free(e);
			j--;
		    }
	    }
	}
	free_matrix((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].flat);
    }
    if (Verbose)
	fprintf(stderr, "mincross %s: %d crossings, %.2f secs.\n",
		agnameof(g), nc, elapsed_sec());
}

static node_t *neighbor(node_t * v, int dir)
{
    node_t *rv;

    rv = NULL;
assert(v);
    if (dir < 0) {
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) > 0)
	    rv = (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->rank)].v[(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) - 1];
    } else
	rv = (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->rank)].v[(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) + 1];
assert((rv == 0) || ((((Agnodeinfo_t*)(((Agobj_t*)(rv))->data))->order)-(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order))*dir > 0);
    return rv;
}

static int is_a_normal_node_of(graph_t * g, node_t * v)
{
    return (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) == 0) && agcontains(g, v));
}

static int is_a_vnode_of_an_edge_of(graph_t * g, node_t * v)
{
    if (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->node_type) == 1)
	&& ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->in).size == 1) && ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).size == 1)) {
	edge_t *e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out).list[0];
	while ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) != 0)
	    e = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_orig);
	if (agcontains(g, e))
	    return (!(0));
    }
    return 0;
}

static int inside_cluster(graph_t * g, node_t * v)
{
    return (is_a_normal_node_of(g, v) | is_a_vnode_of_an_edge_of(g, v));
}

static node_t *furthestnode(graph_t * g, node_t * v, int dir)
{
    node_t *u, *rv;

    rv = u = v;
    while ((u = neighbor(u, dir))) {
	if (is_a_normal_node_of(g, u))
	    rv = u;
	else if (is_a_vnode_of_an_edge_of(g, u))
	    rv = u;
    }
    return rv;
}

void save_vlist(graph_t * g)
{
    int r;

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankleader))
	for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankleader)[r] = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[0];
	}
}

void rec_save_vlists(graph_t * g)
{
    int c;

    save_vlist(g);
    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	rec_save_vlists((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c]);
}


void rec_reset_vlists(graph_t * g)
{
    int r, c;
    node_t *u, *v, *w;

    /* fix vlists of sub-clusters */
    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	rec_reset_vlists((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c]);

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankleader))
	for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	    v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankleader)[r];

	    

	    u = furthestnode(g, v, -1);
	    w = furthestnode(g, v, 1);
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankleader)[r] = u;

	    

	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v = (((Agraphinfo_t*)(((Agobj_t*)(dot_root(g)))->data))->rank)[r].v + (((Agnodeinfo_t*)(((Agobj_t*)(u))->data))->order);
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n = (((Agnodeinfo_t*)(((Agobj_t*)(w))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(u))->data))->order) + 1;
	}
}

/* realFillRanks:
 * The structures in crossing minimization and positioning require
 * that clusters have some node on each rank. This function recursively
 * guarantees this property. It takes into account nodes and edges in
 * a cluster, the latter causing dummy nodes for intervening ranks.
 * For any rank without node, we create a real node of small size. This
 * is stored in the subgraph sg, for easy removal later.
 *
 * I believe it is not necessary to do this for the root graph, as these
 * are laid out one component at a time and these will necessarily have a
 * node on each rank from source to sink levels.
 */
static Agraph_t*
realFillRanks (Agraph_t* g, int rnks[], int rnks_sz, Agraph_t* sg)
{
    int i, c;
    Agedge_t* e;
    Agnode_t* n;

    for (c = 1; c <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_cluster); c++)
	sg = realFillRanks ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->clust)[c], rnks, rnks_sz, sg);

    if (dot_root(g) == g)
	return sg;
    memset (rnks, 0, sizeof(int)*rnks_sz);
    for (n = agfstnode(g); n; n = agnxtnode(g,n)) {
	rnks[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank)] = 1;
	for (e = agfstout(g,n); e; e = agnxtout(g,e)) {
	    for (i = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank)+1; i <= (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank); i++) 
		rnks[i] = 1;
	}
    }
    for (i = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); i++) {
	if (rnks[i] == 0) {
	    if (!sg) {
		sg = agsubg (dot_root(g), "_new_rank", 1);
	    }
	    n = agnode (sg, NULL, 1);
	    agbindrec(n, "Agnodeinfo_t", sizeof(Agnodeinfo_t), (!(0)));
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank) = i;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->lw) = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rw) = 0.5;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->ht) = 1;
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->UF_size) = 1;
	    do {(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list = (edge_t**)zmalloc((4 + 1)*sizeof(edge_t*)); } while (0);
	    do {(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size = 0; (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list = (edge_t**)zmalloc((4 + 1)*sizeof(edge_t*)); } while (0);
	    agsubnode (g, n, 1);
	}
    }
    return sg;
}

static void
fillRanks (Agraph_t* g)
{
    Agraph_t* sg;
    int rnks_sz = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) + 2;
    int* rnks = (int*)zmalloc((rnks_sz)*sizeof(int));
    sg = realFillRanks (g, rnks, rnks_sz, NULL);
    free (rnks);
}

static void init_mincross(graph_t * g)
{
    int size;

    if (Verbose)
	start_timer();

    ReMincross = 0;
    Root = g;
    /* alloc +1 for the null terminator usage in do_ordering() */
    /* also, the +1 avoids attempts to alloc 0 sizes, something
       that efence complains about */
    size = agnedges(dot_root(g)) + 1;
    TE_list = (edge_t **)zmalloc((size)*sizeof(edge_t *));
    TI_list = (int*)zmalloc((size)*sizeof(int));
    mincross_options(g);
    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->flags) & (1 << 4))
	fillRanks (g);
    class2(g);
    decompose(g, 1);
    allocate_ranks(g);
    ordered_edges(g);
    GlobalMinRank = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank);
    GlobalMaxRank = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank);
}

void flat_rev(Agraph_t * g, Agedge_t * e)
{
    int j;
    Agedge_t *rev;

    if (!(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->flat_out).list)
	rev = NULL;
    else
	for (j = 0; (rev = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->flat_out).list[j]); j++)
	    if (((((((Agobj_t*)(rev))->tag).objtype) == 2? (rev): ((rev)-1))->node) == ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node))
		break;
    if (rev) {
	merge_oneway(e, rev);
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt) == 0)
	    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->to_virt) = rev;
	if (((((Agedgeinfo_t*)(((Agobj_t*)(rev))->data))->edge_type) == 4)
	    && ((((Agedgeinfo_t*)(((Agobj_t*)(rev))->data))->to_orig) == 0))
	    (((Agedgeinfo_t*)(((Agobj_t*)(rev))->data))->to_orig) = e;
	do {(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).list = ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).list? (edge_t**)grealloc((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).list,((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).size + 2)*sizeof(edge_t*)):(edge_t**)gmalloc(((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).size + 2)*sizeof(edge_t*))); (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).list[(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).size++] = e; (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).list[(((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->other).size] = NULL;} while(0);
    } else {
	rev = new_virtual_edge(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node), e);
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) == 4)
	    (((Agedgeinfo_t*)(((Agobj_t*)(rev))->data))->edge_type) = 4;
	else
	    (((Agedgeinfo_t*)(((Agobj_t*)(rev))->data))->edge_type) = 3;
	(((Agedgeinfo_t*)(((Agobj_t*)(rev))->data))->label) = (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->label);
	flat_edge(g, rev);
    }
}

static void flat_search(graph_t * g, node_t * v)
{
    int i;
    boolean hascl;
    edge_t *e;
    adjmatrix_t *M = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->rank)].flat;

    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark) = (!(0));
    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->onstack) = (!(0));
    hascl = ((((Agraphinfo_t*)(((Agobj_t*)(dot_root(g)))->data))->n_cluster) > 0);
    if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list)
	for (i = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list[i]); i++) {
	    if (hascl
		&& (!(agcontains(g, ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node)) && agcontains(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node)))))
		continue;
	    if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) == 0)
		continue;
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->onstack) == (!(0))) {
		assert((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->low) < M->nrows);
		assert((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->low) < M->ncols);
		(M->data[(((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->low))*M->ncols)+((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->low))]) = 1;
		delete_flat_edge(e);
		i--;
		if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->edge_type) == 4)
		    continue;
		flat_rev(g, e);
	    } else {
		assert((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->low) < M->nrows);
		assert((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->low) < M->ncols);
		(M->data[(((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->low))*M->ncols)+((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->low))]) = 1;
		if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->mark) == 0)
		    flat_search(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node));
	    }
	}
    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->onstack) = 0;
}

static void flat_breakcycles(graph_t * g)
{
    int i, r, flat;
    node_t *v;

    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	flat = 0;
	for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	    v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
	    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark) = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->onstack) = 0;
	    (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->low) = i;
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).size > 0) && (flat == 0)) {
		(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].flat =
		    new_matrix((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n);
		flat = 1;
	    }
	}
	if (flat) {
	    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
		v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
		if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark) == 0)
		    flat_search(g, v);
	    }
	}
    }
}

/* allocate_ranks:
 * Allocate rank structure, determining number of nodes per rank.
 * Note that no nodes are put into the structure yet.
 */
void allocate_ranks(graph_t * g)
{
    int r, low, high, *cn;
    node_t *n;
    edge_t *e;

    cn = (int*)zmalloc(((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) + 2)*sizeof(int));	/* must be 0 based, not GD_minrank */
    for (n = agfstnode(g); n; n = agnxtnode(g, n)) {
	cn[(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank)]++;
	for (e = agfstout(g, n); e; e = agnxtout(g, e)) {
	    low = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->rank);
	    high = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->rank);
	    if (low > high) {
		int t = low;
		low = high;
		high = t;
	    }
	    for (r = low + 1; r < high; r++)
		cn[r]++;
	}
    }
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank) = (rank_t*)zmalloc(((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) + 2)*sizeof(rank_t));
    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].an = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n = cn[r];
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].av = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v = (node_t **)zmalloc((cn[r] + 1)*sizeof(node_t *));
    }
    free(cn);
}

/* install a node at the current right end of its rank */
void install_in_rank(graph_t * g, node_t * n)
{
    int i, r;

    r = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->rank);
    i = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n;
    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].an <= 0) {
	agerr(AGERR, "install_in_rank, line %d: %s %s rank %d i = %d an = 0\n",
	      1034, agnameof(g), agnameof(n), r, i);
	return;
    }

    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i] = n;
    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order) = i;
    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n++;
    assert((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].an);

    
	

	
	    
		
	
    

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order) > (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].an) {
	agerr(AGERR, "install_in_rank, line %d: ND_order(%s) [%d] > GD_rank(Root)[%d].an [%d]\n",
	      1052, agnameof(n), (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order), r, (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].an);
	return;
    }
    if ((r < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank)) || (r > (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank))) {
	agerr(AGERR, "install_in_rank, line %d: rank %d not in rank range [%d,%d]\n",
	      1057, r, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank), (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank));
	return;
    }
    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order) >
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].av + (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].an) {
	agerr(AGERR, "install_in_rank, line %d: GD_rank(g)[%d].v + ND_order(%s) [%d] > GD_rank(g)[%d].av + GD_rank(Root)[%d].an [%d]\n",
	      1062, r, agnameof(n),(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v + (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->order), r, r, (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].av+(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].an);
	return;
    }
}

/*	install nodes in ranks. the initial ordering ensure that series-parallel
 *	graphs such as trees are drawn with no crossings.  it tries searching
 *	in- and out-edges and takes the better of the two initial orderings.
 */
void build_ranks(graph_t * g, int pass)
{
    int i, j;
    node_t *n, *n0;
    edge_t **otheredges;
    nodequeue *q;

    q = new_queue((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->n_nodes));
    for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next))
	((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mark)) = 0;


    
	
	
	    
		
	    
		
	
    


    for (i = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); i++)
	(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n = 0;

    for (n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->nlist); n; n = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->next)) {
	otheredges = ((pass == 0) ? (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list : (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list);
	if (otheredges[0] != NULL)
	    continue;
	if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mark)) == 0) {
	    ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mark)) = (!(0));
	    enqueue(q, n);
	    while ((n0 = dequeue(q))) {
		if ((((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->ranktype) != 7) {
		    install_in_rank(g, n0);
		    enqueue_neighbors(q, n0, pass);
		} else {
		    install_cluster(g, n0, pass, q);
		}
	    }
	}
    }
    if (dequeue(q))
	agerr(AGERR, "surprise\n");
    for (i = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); i <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); i++) {
	(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[i].valid = 0;
	if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1) && ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n > 0)) {
	    int n, ndiv2;
	    node_t **vlist = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].v;
	    n = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[i].n - 1;
	    ndiv2 = n / 2;
	    for (j = 0; j <= ndiv2; j++)
		exchange(vlist[j], vlist[n - j]);
	}
    }

    if ((g == dot_root(g)) && ncross(g) > 0)
	transpose(g, 0);
    free_queue(q);
}

void enqueue_neighbors(nodequeue * q, node_t * n0, int pass)
{
    int i;
    edge_t *e;

    if (pass == 0) {
	for (i = 0; i < (((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->out).size; i++) {
	    e = (((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->out).list[i];
	    if ((((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->mark))) == 0) {
		((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->mark)) = (!(0));
		enqueue(q, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node));
	    }
	}
    } else {
	for (i = 0; i < (((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->in).size; i++) {
	    e = (((Agnodeinfo_t*)(((Agobj_t*)(n0))->data))->in).list[i];
	    if ((((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->mark))) == 0) {
		((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->mark)) = (!(0));
		enqueue(q, ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node));
	    }
	}
    }
}

static int constraining_flat_edge(Agraph_t *g, Agnode_t *v, Agedge_t *e)
{
	if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) == 0) return 0;
	if (!inside_cluster(g,((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node))) return 0;
	if (!inside_cluster(g,((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))) return 0;
	return (!(0));
}


/* construct nodes reachable from 'here' in post-order.
* This is the same as doing a topological sort in reverse order.
*/
static int postorder(graph_t * g, node_t * v, node_t ** list, int r)
{
    edge_t *e;
    int i, cnt = 0;

    ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark)) = (!(0));
    if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).size > 0) {
	for (i = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list[i]); i++) {
	    if (!constraining_flat_edge(g,v,e)) continue;
	    if (((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->mark)) == 0)
		cnt += postorder(g, ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node), list + cnt, r);
	}
    }
    assert((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->rank) == r);
    list[cnt++] = v;
    return cnt;
}

static void flat_reorder(graph_t * g)
{
    int i, j, r, pos, n_search, local_in_cnt, local_out_cnt, base_order;
    node_t *v, **left, **right, *t;
    node_t **temprank = NULL;
    edge_t *flat_e, *e;

    if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->has_flat_edges) == 0)
	return;
    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r <= (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n == 0) continue;
	base_order = (((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[0]))->data))->order);
	for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++)
	    ((((Agnodeinfo_t*)(((Agobj_t*)((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i]))->data))->mark)) = 0;
	temprank = (temprank? (node_t **)grealloc(temprank,(i + 1)*sizeof(node_t *)):(node_t **)gmalloc((i + 1)*sizeof(node_t *)));
	pos = 0;

	/* construct reverse topological sort order in temprank */
	for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
	    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
	    else v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[(((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n - i - 1];

	    local_in_cnt = local_out_cnt = 0;
	    for (j = 0; j < (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_in).size; j++) {
		flat_e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_in).list[j];
		if (constraining_flat_edge(g,v,flat_e)) local_in_cnt++;
	    }
	    for (j = 0; j < (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).size; j++) {
		flat_e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list[j];
		if (constraining_flat_edge(g,v,flat_e)) local_out_cnt++;
	    }
	    if ((local_in_cnt == 0) && (local_out_cnt == 0))
		temprank[pos++] = v;
	    else {
		if ((((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->mark)) == 0) && (local_in_cnt == 0)) {
		    left = temprank + pos;
		    n_search = postorder(g, v, left, r);
		    pos += n_search;
		}
	    }
	}

	if (pos) {
	    if (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1) == 0) {
		left = temprank;
		right = temprank + pos - 1;
		while (left < right) {
		    t = *left;
		    *left = *right;
		    *right = t;
		    left++;
		    right--;
		}
	    }
	    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
		v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i] = temprank[i];
		(((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->order) = i + base_order;
	    }

	    /* nonconstraint flat edges must be made LR */
	    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; i++) {
		v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[i];
		if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list) {
		    for (j = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->flat_out).list[j]); j++) {
			if ( ((((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1) == 0) && ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order) < (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order))) ||
				 ( (((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rankdir & 0x3) & 1)) && ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order) > (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order) ))) {
			    assert(constraining_flat_edge(g,v,e) == 0);
			    delete_flat_edge(e);
			    j--;
			    flat_rev(g, e);
			}
		    }
		}
	    }
	    /* postprocess to restore intended order */
	}
	/* else do no harm! */
	(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].valid = 0;
    }
    if (temprank)
	free(temprank);
}

static void reorder(graph_t * g, int r, int reverse, int hasfixed)
{
    int changed = 0, nelt;
    boolean muststay, sawclust;
    node_t **vlist = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v;
    node_t **lp, **rp, **ep = vlist + (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n;

    for (nelt = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n - 1; nelt >= 0; nelt--) {
	lp = vlist;
	while (lp < ep) {
	    /* find leftmost node that can be compared */
	    while ((lp < ep) && ((((Agnodeinfo_t*)(((Agobj_t*)(*lp))->data))->mval) < 0))
		lp++;
	    if (lp >= ep)
		break;
	    /* find the node that can be compared */
	    sawclust = muststay = 0;
	    for (rp = lp + 1; rp < ep; rp++) {
		if (sawclust && (((Agnodeinfo_t*)(((Agobj_t*)(*rp))->data))->clust))
		    continue;	/* ### */
		if (left2right(g, *lp, *rp)) {
		    muststay = (!(0));
		    break;
		}
		if ((((Agnodeinfo_t*)(((Agobj_t*)(*rp))->data))->mval) >= 0)
		    break;
		if ((((Agnodeinfo_t*)(((Agobj_t*)(*rp))->data))->clust))
		    sawclust = (!(0));	/* ### */
	    }
	    if (rp >= ep)
		break;
	    if (muststay == 0) {
		register int p1 = ((((Agnodeinfo_t*)(((Agobj_t*)(*lp))->data))->mval));
		register int p2 = ((((Agnodeinfo_t*)(((Agobj_t*)(*rp))->data))->mval));
		if ((p1 > p2) || ((p1 == p2) && (reverse))) {
		    exchange(*lp, *rp);
		    changed++;
		}
	    }
	    lp = rp;
	}
	if ((hasfixed == 0) && (reverse == 0))
	    ep--;
    }

    if (changed) {
	(((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r].valid = 0;
	if (r > 0)
	    (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r - 1].valid = 0;
    }
}

static void mincross_step(graph_t * g, int pass)
{
    int r, other, first, last, dir;
    int hasfixed, reverse;

    if ((pass % 4) < 2)
	reverse = (!(0));
    else
	reverse = 0;
    if (pass % 2) {
	r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) - 1;
	dir = -1;
    } /* up pass */
    else {
	r = 1;
	dir = 1;
    }				/* down pass */

    if (pass % 2 == 0) {	/* down pass */
	first = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) + 1;
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank) > (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->minrank))
	    first--;
	last = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank);
	dir = 1;
    } else {			/* up pass */
	first = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) - 1;
	last = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank);
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank) < (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->maxrank))
	    first++;
	dir = -1;
    }

    for (r = first; r != last + dir; r += dir) {
	other = r - dir;
	hasfixed = medians(g, r, other);
	reorder(g, r, reverse, hasfixed);
    }
    transpose(g, (!(reverse)));
}

static int local_cross(elist l, int dir)
{
    int i, j, is_out;
    int cross = 0;
    edge_t *e, *f;
    if (dir > 0)
	is_out = (!(0));
    else
	is_out = 0;
    for (i = 0; (e = l.list[i]); i++) {
	if (is_out)
	    for (j = i + 1; (f = l.list[j]); j++) {
		if (((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 2?(f):((f)-1))->node)))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order))
			 * ((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->tail_port).p.x - (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port).p.x) < 0)
		    cross += (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xpenalty) * (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->xpenalty);
	} else
	    for (j = i + 1; (f = l.list[j]); j++) {
		if (((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(f))->tag).objtype) == 3?(f):((f)+1))->node)))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order))
			* ((((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->head_port).p.x - (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port).p.x) < 0)
		    cross += (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xpenalty) * (((Agedgeinfo_t*)(((Agobj_t*)(f))->data))->xpenalty);
	    }
    }
    return cross;
}

static int rcross(graph_t * g, int r)
{
    static int *Count, C;
    int top, bot, cross, max, i, k;
    node_t **rtop, *v;

    cross = 0;
    max = 0;
    rtop = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v;

    if (C <= (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r + 1].n) {
	C = (((Agraphinfo_t*)(((Agobj_t*)(Root))->data))->rank)[r + 1].n + 1;
	Count = (Count? (int*)grealloc(Count,(C)*sizeof(int)):(int*)gmalloc((C)*sizeof(int)));
    }

    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].n; i++)
	Count[i] = 0;

    for (top = 0; top < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; top++) {
	register edge_t *e;
	if (max > 0) {
	    for (i = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(rtop[top]))->data))->out).list[i]); i++) {
		for (k = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order) + 1; k <= max; k++)
		    cross += Count[k] * (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xpenalty);
	    }
	}
	for (i = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(rtop[top]))->data))->out).list[i]); i++) {
	    register int inv = (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order);
	    if (inv > max)
		max = inv;
	    Count[inv] += (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xpenalty);
	}
    }
    for (top = 0; top < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].n; top++) {
	v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].v[top];
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->has_port))
	    cross += local_cross((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->out), 1);
    }
    for (bot = 0; bot < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].n; bot++) {
	v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r + 1].v[bot];
	if ((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->has_port))
	    cross += local_cross((((Agnodeinfo_t*)(((Agobj_t*)(v))->data))->in), -1);
    }
    return cross;
}

int ncross(graph_t * g)
{
    int r, count, nc;

    g = Root;
    count = 0;
    for (r = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->minrank); r < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->maxrank); r++) {
	if ((((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].valid)
	    count += (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].cache_nc;
	else {
	    nc = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].cache_nc = rcross(g, r);
	    count += nc;
	    (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r].valid = (!(0));
	}
    }
    return count;
}

static int ordercmpf(int *i0, int *i1)
{
    return (*i0) - (*i1);
}

/* flat_mval:
 * Calculate a mval for nodes with no in or out non-flat edges.
 * Assume (ND_out(n).size == 0) && (ND_in(n).size == 0)
 * Find flat edge a->n where a has the largest order and set
 * n.mval = a.mval+1, assuming a.mval is defined (>=0).
 * If there are no flat in edges, find flat edge n->a where a 
 * has the smallest order and set * n.mval = a.mval-1, assuming 
 * a.mval is > 0.
 * Return true if n.mval is left -1, indicating a fixed node for sorting.
 */
static int flat_mval(node_t * n)
{
    int i;
    edge_t *e, **fl;
    node_t *nn;

    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->flat_in).size > 0) {
	fl = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->flat_in).list;
	nn = ((((((Agobj_t*)(fl[0]))->tag).objtype) == 3? (fl[0]): ((fl[0])+1))->node);
	for (i = 1; (e = fl[i]); i++)
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order) > (((Agnodeinfo_t*)(((Agobj_t*)(nn))->data))->order))
		nn = ((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node);
	if ((((Agnodeinfo_t*)(((Agobj_t*)(nn))->data))->mval) >= 0) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = (((Agnodeinfo_t*)(((Agobj_t*)(nn))->data))->mval) + 1;
	    return 0;
	}
    } else if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->flat_out).size > 0) {
	fl = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->flat_out).list;
	nn = ((((((Agobj_t*)(fl[0]))->tag).objtype) == 2? (fl[0]): ((fl[0])-1))->node);
	for (i = 1; (e = fl[i]); i++)
	    if ((((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order) < (((Agnodeinfo_t*)(((Agobj_t*)(nn))->data))->order))
		nn = ((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node);
	if ((((Agnodeinfo_t*)(((Agobj_t*)(nn))->data))->mval) > 0) {
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = (((Agnodeinfo_t*)(((Agobj_t*)(nn))->data))->mval) - 1;
	    return 0;
	}
    }
    return (!(0));
}



static boolean medians(graph_t * g, int r0, int r1)
{
    int i, j, j0, lm, rm, lspan, rspan, *list;
    node_t *n, **v;
    edge_t *e;
    boolean hasfixed = 0;

    list = TI_list;
    v = (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r0].v;
    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r0].n; i++) {
	n = v[i];
	j = 0;
	if (r1 > r0)
	    for (j0 = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).list[j0]); j0++) {
		if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xpenalty) > 0)
		    list[j++] = (256 * (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 2?(e):((e)-1))->node)))->data))->order) + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->head_port)).order);
	} else
	    for (j0 = 0; (e = (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).list[j0]); j0++) {
		if ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->xpenalty) > 0)
		    list[j++] = (256 * (((Agnodeinfo_t*)(((Agobj_t*)(((((((Agobj_t*)(e))->tag).objtype) == 3?(e):((e)+1))->node)))->data))->order) + ((((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->tail_port)).order);
	    }
	switch (j) {
	case 0:
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = -1;
	    break;
	case 1:
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = list[0];
	    break;
	case 2:
	    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = (list[0] + list[1]) / 2;
	    break;
	default:
	    qsort(list, j, sizeof(int), (qsort_cmpf) ordercmpf);
	    if (j % 2)
		(((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = list[j / 2];
	    else {
		/* weighted median */
		rm = j / 2;
		lm = rm - 1;
		rspan = list[j - 1] - list[rm];
		lspan = list[lm] - list[0];
		if (lspan == rspan)
		    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = (list[lm] + list[rm]) / 2;
		else {
		    int w = list[lm] * rspan + list[rm] * lspan;
		    (((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->mval) = w / (lspan + rspan);
		}
	    }
	}
    }
    for (i = 0; i < (((Agraphinfo_t*)(((Agobj_t*)(g))->data))->rank)[r0].n; i++) {
	n = v[i];
	if (((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->out).size == 0) && ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->in).size == 0))
	    hasfixed |= flat_mval(n);
    }
    return hasfixed;
}

static int nodeposcmpf(node_t ** n0, node_t ** n1)
{
    return ((((Agnodeinfo_t*)(((Agobj_t*)(*n0))->data))->order) - (((Agnodeinfo_t*)(((Agobj_t*)(*n1))->data))->order));
}

static int edgeidcmpf(edge_t ** e0, edge_t ** e1)
{
    return (((((Agobj_t*)(*e0))->tag).seq) - ((((Agobj_t*)(*e1))->tag).seq));
}

/* following code deals with weights of edges of "virtual" nodes */










static int table[3][3] = {
    /* ordinary */ {1, 1, 1},
    /* singleton */ {1, 2, 2},
    /* virtual */ {1, 2, 4}
};

static int endpoint_class(node_t * n)
{
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->node_type) == 1)
	return 2;
    if ((((Agnodeinfo_t*)(((Agobj_t*)(n))->data))->weight_class) <= 1)
	return 1;
    return 0;
}

void virtual_weight(edge_t * e)
{
    int t;
    t = table[endpoint_class(((((((Agobj_t*)(e))->tag).objtype) == 3? (e): ((e)+1))->node))][endpoint_class(((((((Agobj_t*)(e))->tag).objtype) == 2? (e): ((e)-1))->node))];
    (((Agedgeinfo_t*)(((Agobj_t*)(e))->data))->weight) *= t;
}




    
    

    
    
	
	
	
	    
	    
		
		
		    
	    
		
		
		
		
	    
	
	
    




    
    
    

    
	
	
	    
	    
	
    



static void mincross_options(graph_t * g)
{
    char *p;
    double f;

    /* set default values */
    MinQuit = 8;
    MaxIter = 24;
    Convergence = .995;

    p = agget(g, "mclimit");
    if (p && ((f = atof(p)) > 0.0)) {
	MinQuit = ((1)>(MinQuit * f)?(1):(MinQuit * f));
	MaxIter = ((1)>(MaxIter * f)?(1):(MaxIter * f));
    }
}




    
    

    
	
    
    
    
    

    
	
	
	    
    




    
    

    
	
	    
	    
	    
	
	
	    
	    
	    
	
    
    
	




    

    
	
	    
    
	


