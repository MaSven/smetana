#line 1 "graphviz-2.38.0\\lib\\sfio\\sfsetbuf.c" 1
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







#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1
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











/*	Internal definitions for sfio.
**	Written by Kiem-Phong Vo
*/

#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio_t.h" 1
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








/*	This header file is for library writers who need to know certain
**	internal info concerning the full Sfio_t structure. Including this
**	file means that you agree to track closely with sfio development
**	in case its internal architecture is changed.
**
**	Written by Kiem-Phong Vo
*/

/* the parts of Sfio_t private to sfio functions */
















#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
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










/*	Public header file for the sfio library
**
**	Written by Kiem-Phong Vo
*/




#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1

#line 1 "graphviz-2.38.0\\lib\\sfio\\sfio.h" 1
































































/* Sfoff_t should be large enough for largest file address */







	typedef struct _sfio_s Sfio_t;

    typedef struct _sfdisc_s Sfdisc_t;
    typedef ssize_t(*Sfread_f)
	_ARG_((Sfio_t *, Void_t *, size_t, Sfdisc_t *));
    typedef ssize_t(*Sfwrite_f)
	_ARG_((Sfio_t *, const Void_t *, size_t, Sfdisc_t *));
    typedef _ast_intmax_t(*Sfseek_f) _ARG_((Sfio_t *, _ast_intmax_t, int, Sfdisc_t *));
    typedef int (*Sfexcept_f) _ARG_((Sfio_t *, int, Void_t *, Sfdisc_t *));

/* discipline structure */
    struct _sfdisc_s {
	Sfread_f readf;		/* read function                */
	Sfwrite_f writef;	/* write function               */
	Sfseek_f seekf;		/* seek function                */
	Sfexcept_f exceptf;	/* to handle exceptions         */
	Sfdisc_t *disc;		/* the continuing discipline    */
    };

/* a file structure */
    struct _sfio_s {
	unsigned char *next;	/* next position to read/write from     */
	unsigned char *endw;	/* end of write buffer                  */
	unsigned char *endr;	/* end of read buffer                   */
	unsigned char *endb;	/* end of buffer                        */
	Sfio_t *push;		/* the stream that was pushed on        */
	unsigned short flags;	/* type of stream                       */
	short file;		/* file descriptor                      */
	unsigned char *data;	/* base of data buffer                  */
	ssize_t size;		/* buffer size                          */
	ssize_t val;		/* values or string lengths             */

	 _ast_intmax_t extent; _ast_intmax_t here; unsigned char getr; unsigned char tiny[1]; unsigned short bits; unsigned int mode; struct _sfdisc_s* disc; struct _sfpool_s* pool; struct _sfrsrv_s* rsrv; struct _sfproc_s* proc; Void_t* mutex; Void_t* stdio; _ast_intmax_t lpos; size_t iosz;

    };

/* formatting environment */
    typedef struct _sffmt_s Sffmt_t;
    typedef int (*Sffmtext_f) _ARG_((Sfio_t *, Void_t *, Sffmt_t *));
    typedef int (*Sffmtevent_f)
	_ARG_((Sfio_t *, int, Void_t *, Sffmt_t *));
    struct _sffmt_s {
	long version;		/* version of this structure            */
	Sffmtext_f extf;	/* function to process arguments        */
	Sffmtevent_f eventf;	/* process events                       */

	char *form;		/* format string to stack               */
	va_list args;		/* corresponding arg list               */

	int fmt;		/* format character                     */
	ssize_t size;		/* object size                          */
	int flags;		/* formatting flags                     */
	int width;		/* width of field                       */
	int precis;		/* precision required                   */
	int base;		/* conversion base                      */

	char *t_str;		/* type string                          */
	ssize_t n_str;		/* length of t_str                      */

	Void_t *noop;		/* as yet unused                        */
    };
























/* for sfmutex() call */





/* various constants */













/* bits for various types of files */







    /* but BSDI stat.h now uses this symbol. */
    /* So we leave it out in such cases.    */




















/* for sfgetr/sfreserve to hold a record */



/* exception events: SF_NEW(0), SF_READ(1), SF_WRITE(2) and the below 	*/





    /* but AIX now uses this symbol. So we  */
    /* avoid defining it in such cases.     */














/* for stack and disciplines */



/* for the notify function and discipline exception */






     1 extern ssize_t _Sfi;




/* standard in/out/err streams */
    extern Sfio_t *sfstdin;
    extern Sfio_t *sfstdout;
    extern Sfio_t *sfstderr;
    extern Sfio_t _Sfstdin;
    extern Sfio_t _Sfstdout;
    extern Sfio_t _Sfstderr;















    extern Sfio_t *sfnew _ARG_((Sfio_t *, Void_t *, size_t, int, int));
    extern Sfio_t *sfopen _ARG_((Sfio_t *, const char *, const char *));
    extern Sfio_t *sfpopen _ARG_((Sfio_t *, const char *, const char *));
    extern Sfio_t *sfstack _ARG_((Sfio_t *, Sfio_t *));
    extern Sfio_t *sfswap _ARG_((Sfio_t *, Sfio_t *));
    extern Sfio_t *sftmp _ARG_((size_t));
    extern int sfpurge _ARG_((Sfio_t *));
    extern int sfpoll _ARG_((Sfio_t **, int, int));
    extern Void_t *sfreserve _ARG_((Sfio_t *, ssize_t, int));
    extern int sfsync _ARG_((Sfio_t *));
    extern int sfclrlock _ARG_((Sfio_t *));
    extern Void_t *sfsetbuf _ARG_((Sfio_t *, Void_t *, size_t));
    extern Sfdisc_t *sfdisc _ARG_((Sfio_t *, Sfdisc_t *));
    extern int sfraise _ARG_((Sfio_t *, int, Void_t *));
    extern int sfnotify _ARG_((void (*)(Sfio_t *, int, int)));
    extern int sfset _ARG_((Sfio_t *, int, int));
    extern int sfsetfd _ARG_((Sfio_t *, int));
    extern Sfio_t *sfpool _ARG_((Sfio_t *, Sfio_t *, int));
    extern ssize_t sfread _ARG_((Sfio_t *, Void_t *, size_t));
    extern ssize_t sfwrite _ARG_((Sfio_t *, const Void_t *, size_t));
    extern _ast_intmax_t sfmove _ARG_((Sfio_t *, Sfio_t *, _ast_intmax_t, int));
    extern int sfclose _ARG_((Sfio_t *));
    extern _ast_intmax_t sftell _ARG_((Sfio_t *));
    extern _ast_intmax_t sfseek _ARG_((Sfio_t *, _ast_intmax_t, int));
    extern ssize_t sfputr _ARG_((Sfio_t *, const char *, int));
    extern char *sfgetr _ARG_((Sfio_t *, int, int));
    extern ssize_t sfnputc _ARG_((Sfio_t *, int, size_t));
    extern int sfungetc _ARG_((Sfio_t *, int));
    extern int sfprintf _ARG_((Sfio_t *, const char *, ...));
    extern char *sfprints _ARG_((const char *, ...));
    extern int sfsprintf _ARG_((char *, int, const char *, ...));
    extern int sfvsprintf _ARG_((char *, int, const char *, va_list));
    extern int sfvprintf _ARG_((Sfio_t *, const char *, va_list));
    extern int sfscanf _ARG_((Sfio_t *, const char *, ...));
    extern int sfsscanf _ARG_((const char *, const char *, ...));
    extern int sfvsscanf _ARG_((const char *, const char *, va_list));
    extern int sfvscanf _ARG_((Sfio_t *, const char *, va_list));
    extern int sfresize _ARG_((Sfio_t *, _ast_intmax_t));

/* mutex locking for thread-safety */
    extern int sfmutex _ARG_((Sfio_t *, int));

/* io functions with discipline continuation */
    extern ssize_t sfrd _ARG_((Sfio_t *, Void_t *, size_t, Sfdisc_t *));
    extern ssize_t sfwr
	_ARG_((Sfio_t *, const Void_t *, size_t, Sfdisc_t *));
    extern _ast_intmax_t sfsk _ARG_((Sfio_t *, _ast_intmax_t, int, Sfdisc_t *));
    extern ssize_t sfpkrd _ARG_((int, Void_t *, size_t, int, long, int));

/* portable handling of primitive types */
    extern int sfdlen _ARG_((_ast_fltmax_t));
    extern int sfllen _ARG_((_ast_intmax_t));
    extern int sfulen _ARG_((unsigned _ast_intmax_t));

    extern int sfputd _ARG_((Sfio_t *, _ast_fltmax_t));
    extern int sfputl _ARG_((Sfio_t *, _ast_intmax_t));
    extern int sfputu _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int sfputm _ARG_((Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t));
    extern int sfputc _ARG_((Sfio_t *, int));

    extern _ast_fltmax_t sfgetd _ARG_((Sfio_t *));
    extern _ast_intmax_t sfgetl _ARG_((Sfio_t *));
    extern unsigned _ast_intmax_t sfgetu _ARG_((Sfio_t *));
    extern unsigned _ast_intmax_t sfgetm _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int sfgetc _ARG_((Sfio_t *));

    extern int _sfputd _ARG_((Sfio_t *, _ast_fltmax_t));
    extern int _sfputl _ARG_((Sfio_t *, _ast_intmax_t));
    extern int _sfputu _ARG_((Sfio_t *, unsigned _ast_intmax_t));
    extern int _sfputm _ARG_((Sfio_t *, unsigned _ast_intmax_t, unsigned _ast_intmax_t));
    extern int _sfflsbuf _ARG_((Sfio_t *, int));

    extern int _sffilbuf _ARG_((Sfio_t *, int));

    extern int _sfdlen _ARG_((_ast_fltmax_t));
    extern int _sfllen _ARG_((_ast_intmax_t));
    extern int _sfulen _ARG_((unsigned _ast_intmax_t));

/* miscellaneous function analogues of fast in-line functions */
    extern _ast_intmax_t sfsize _ARG_((Sfio_t *));
    extern int sfclrerr _ARG_((Sfio_t *));
    extern int sfeof _ARG_((Sfio_t *));
    extern int sferror _ARG_((Sfio_t *));
    extern int sffileno _ARG_((Sfio_t *));
    extern int sfstacked _ARG_((Sfio_t *));
    extern ssize_t sfvalue _ARG_((Sfio_t *));
    extern ssize_t sfslen _ARG_((void));


     _END_EXTERNS_
/* coding long integers in a portable and compact fashion */




































     
	
    
	
    
    
	
    
    
	
    

    
	
    
    
	
    

    
	
    
    
	
    
    
	
    

    
	
    
    
	
    
    
	
    
    
	
    
    
	
    
    
	
    






















#line 44 "graphviz-2.38.0\\lib\\sfio\\sfio_t.h" 2

/* mode bit to indicate that the structure hasn't been initialized */


/* short-hand for common stream types */





/* for static initialization of an Sfio_t structure */



























/* function to clear an Sfio_t structure */
































#line 25 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 2

/* note that the macro vt_threaded has effect on vthread.h */
#line 1 "graphviz-2.38.0\\lib\\sfio\\vthread.h" 1
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










/*	Header for the Vthread library.
**	Note that the macro vt_threaded may be defined
**	outside of vthread.h to suppress threading.
**
**	Written by Kiem-Phong Vo
*/

#line 1 "graphviz-2.38.0\\lib\\sfio\\vthread.h" 1
#line 1 "graphviz-2.38.0\\lib\\sfio\\vthread.h" 1

/* ast doesn't do threads yet */
















    
    
    
    
    










    
    
    
    
    






/* common attributes for various structures */







/* directives for vtset() */


    typedef struct _vtmutex_s Vtmutex_t;
    typedef struct _vtonce_s Vtonce_t;
    typedef struct _vthread_s Vthread_t;














     1 extern Vthread_t *vtopen _ARG_((Vthread_t *, int));
    extern int vtclose _ARG_((Vthread_t *));
    extern int vtset _ARG_((Vthread_t *, int, Void_t *));
    extern int vtrun _ARG_((Vthread_t *, void *(*)(void *), void *));
    extern int vtkill _ARG_((Vthread_t *));
    extern int vtwait _ARG_((Vthread_t *));

/*    extern int vtonce _ARG_((Vtonce_t *, void (*)())); */

    extern Vtmutex_t *vtmtxopen _ARG_((Vtmutex_t *, int));
    extern int vtmtxclose _ARG_((Vtmutex_t *));
    extern int vtmtxlock _ARG_((Vtmutex_t *));
    extern int vtmtxtrylock _ARG_((Vtmutex_t *));
    extern int vtmtxunlock _ARG_((Vtmutex_t *));
    extern int vtmtxclrlock _ARG_((Vtmutex_t *));

    extern Void_t *vtstatus _ARG_((Vthread_t *));
    extern int vterror _ARG_((Vthread_t *));
    extern int vtmtxerror _ARG_((Vtmutex_t *));
    extern int vtonceerror _ARG_((Vtonce_t *));

     _END_EXTERNS_


	
	
	
	
	
	
    


    
	
	
	
	
	
	
	
    


    
	
	
	
    














/* fake structures and functions */

    struct _vtmutex_s {
	int error;
    };
    struct _vtattr_s {
	int error;
    };
    struct _vthread_s {
	int error;
    };
    struct _vtonce_s {
	int error;
    };































#line 28 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 2

/* file system info */





























/* when building the binary compatibility package, a number of header files
   are not needed and they may get in the way so we remove them here.
*/





























































#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1



















#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1
#line 1 "graphviz-2.38.0\\lib\\sfio\\sfhdr.h" 1






































/* functions for polling readiness of streams */


























/* to test for executable access mode of a file */




/* alternative process forking */























































































/* 64-bit vs 32-bit file stuff */


    





    



/* to get rid of pesky compiler warnings */






/* Private flags in the "bits" field */







/* this bit signals sfmutex() not to create a mutex for a private stream */


/* on closing, don't be a hero about reread/rewrite on interrupts */


/* private flags that must be cleared in sfclrlock */







/* bits for the mode field, SF_INIT defined in sfio_t.h */



















/* short-hands */

















/* macros do determine stream types from Stat_t data */








































/* set close-on-exec */












/* a couple of error number that we use, default values are like Linux */


















/* see if we can use memory mapping for io */

















/* function to get the decimal point for local environment */





























/* stream pool structure. */
    typedef struct _sfpool_s Sfpool_t;
    struct _sfpool_s {
	Sfpool_t *next;
	int mode;		/* type of pool                 */
	int s_sf;		/* size of pool array           */
	int n_sf;		/* number currently in pool     */
	Sfio_t **sf;		/* array of streams             */
	Sfio_t *array[3];	/* start with 3                 */
	Vtmutex_t mutex;	/* mutex lock object            */
    };

/* reserve buffer structure */
    typedef struct _sfrsrv_s Sfrsrv_t;
    struct _sfrsrv_s {
	ssize_t slen;		/* last string length           */
	ssize_t size;		/* buffer size                  */
	unsigned char data[1];		/* data buffer                  */
    };

/* co-process structure */
    typedef struct _sfproc_s Sfproc_t;
    struct _sfproc_s {
	int pid;		/* process id                   */
	unsigned char *rdata;		/* read data being cached       */
	int ndata;		/* size of cached data          */
	int size;		/* buffer size                  */
	int file;		/* saved file descriptor        */
	int sigp;		/* sigpipe protection needed    */
    };

/* extensions to sfvprintf/sfvscanf */








    typedef struct _fmt_s Fmt_t;
    typedef struct _fmtpos_s Fmtpos_t;
    typedef union {
	int i, *ip;
	long l, *lp;
	short h, *hp;
	unsigned int ui;
	unsigned long ul;
	unsigned short uh;
	_ast_intmax_t ll, *llp;
	unsigned _ast_intmax_t lu;
	_ast_fltmax_t ld;
	double d;
	float f;
	char c, *s, **sp;
	Void_t *vp;
	Sffmt_t *ft;
    } Argv_t;

    struct _fmt_s {
	char *form;		/* format string                */
	va_list args;		/* corresponding arglist        */

	char *oform;		/* original format string       */
	va_list oargs;		/* original arg list            */
	int argn;		/* number of args already used  */
	Fmtpos_t *fp;		/* position list                */

	Sffmt_t *ft;		/* formatting environment       */
	Sffmtevent_f eventf;	/* event function               */
	Fmt_t *next;		/* stack frame pointer          */
    };

    struct _fmtpos_s {
	Sffmt_t ft;		/* environment                  */
	Argv_t argv;		/* argument value               */
	int fmt;		/* original format              */
	int need[5];	/* positions depending on       */
    };























/* format flags&types, must coexist with those in sfio.h */








/* type of elements to be converted */







/* local variables used across sf-functions */













    typedef struct _sfextern_s {
	ssize_t sf_page;
	struct _sfpool_s sf_pool;
	int (*sf_pmove) _ARG_((Sfio_t *, int));
	Sfio_t *(*sf_stack) _ARG_((Sfio_t *, Sfio_t *));
	void (*sf_notify) _ARG_((Sfio_t *, int, int));
	int (*sf_stdsync) _ARG_((Sfio_t *));
	struct _sfdisc_s sf_udisc;
	void (*sf_cleanup) _ARG_((void));
	int sf_exiting;
	int sf_done;
	Vtonce_t *sf_once;
	void (*sf_oncef) _ARG_((void));
	Vtmutex_t *sf_mutex;
    } Sfextern_t;

/* get the real value of a byte in a coded long or ulong */




/* amount of precision to get in each iteration during coding of doubles */


/* grain size for buffer increment */



/* when the buffer is empty, certain io requests may be better done directly
   on the given application buffers. The below condition determines when.
*/



/* number of pages to memory map at a time */


/* set/unset sequential states for mmap */



















/* the bottomless bit bucket */







/* exception types */

























/* lock/open a stream */










/* check to see if the stream can be accessed */




/* set discipline code */
























/* fast peek of a stream */






/* more than this for a line buffer, we might as well flush */


/* safe closing function */


/* string stream extent */





/* control flags for open() */










































/* floating point to ascii conversion */











/* tables for numerical translation */











    typedef struct _sftab_ {
	_ast_fltmax_t sf_pos10[6];	/* positive powers of 10        */
	_ast_fltmax_t sf_neg10[6];	/* negative powers of 10        */
	unsigned char sf_dec[200];	/* ascii reps of values < 100   */
	char *sf_digits;	/* digits for general bases     */
	int (*sf_cvinitf) (void);	/* initialization function      */
	int sf_cvinit;		/* initialization state         */
	Fmtpos_t *(*sf_fmtposf)
	    _ARG_((Sfio_t *, const char *, va_list, int));
	char *(*sf_fmtintf) _ARG_((const char *, int *));
	unsigned char sf_cv36[((unsigned char)(~0)) + 1];	/* conversion for base [2-36]   */
	unsigned char sf_cv64[((unsigned char)(~0)) + 1];	/* conversion for base [37-64]  */
	unsigned char sf_type[((unsigned char)(~0)) + 1];	/* conversion formats&types     */
    } Sftab_t;

/* thread-safe macro/function to initialize _Sfcv* conversion tables */


/* sfucvt() converts decimal integers to ASCII */













































/* handy functions */





/* fast functions for memory copy and memory clear */













/* note that MEMCPY advances the associated pointers */























     1 extern Sfextern_t _Sfextern;
    extern Sftab_t _Sftable;

    extern int _sfpopen _ARG_((Sfio_t *, int, int, int));
    extern int _sfpclose _ARG_((Sfio_t *));
    extern int _sfmode _ARG_((Sfio_t *, int, int));
    extern int _sftype _ARG_((const char *, int *, int *));
    extern int _sfexcept _ARG_((Sfio_t *, int, ssize_t, Sfdisc_t *));
    extern Sfrsrv_t *_sfrsrv _ARG_((Sfio_t *, ssize_t));
    extern int _sfsetpool _ARG_((Sfio_t *));
    extern char *_sfcvt _ARG_((Void_t *, int, int *, int *, int));
    extern char **_sfgetpath _ARG_((char *));
    extern _ast_fltmax_t _sfstrtod _ARG_((const char *, char **));






    _astimport int errno;


/* for portable encoding of double values */


    extern double frexp _ARG_((double, int *));
    extern double ldexp _ARG_((double, int));




    extern Void_t *mmap _ARG_((Void_t *, size_t, int, int, int, off_t));
    extern int munmap _ARG_((Void_t *, size_t));





    extern void abort _ARG_((void));
    extern int atexit _ARG_((void (*)(void)));
    extern char *getenv _ARG_((const char *));
    extern void *malloc _ARG_((size_t));
    extern void *realloc _ARG_((void *, size_t));
    extern void free _ARG_((void *));
    extern size_t strlen _ARG_((const char *));
    extern char *strcpy _ARG_((char *, const char *));

    extern Void_t *memset _ARG_((void *, int, size_t));
    extern Void_t *memchr _ARG_((const void *, int, size_t));
    extern Void_t *memccpy _ARG_((void *, const void *, int, size_t));

    extern Void_t *memcpy _ARG_((void *, const void *, size_t));


    


    extern int remove _ARG_((const char *));









    extern int close _ARG_((int));
    extern ssize_t read _ARG_((int, void *, size_t));
    extern ssize_t write _ARG_((int, const void *, size_t));
    extern off_t lseek _ARG_((int, off_t, int));
    extern int dup _ARG_((int));
    extern int isatty _ARG_((int));
    extern int wait _ARG_((int *));
    extern int pipe _ARG_((int *));
    extern int access _ARG_((const char *, int));
    extern unsigned int sleep _ARG_((unsigned int));
    extern int execl _ARG_((const char *, const char *, ...));
    extern int execv _ARG_((const char *, char **));

    extern int fork _ARG_((void));


    






    


    


    extern time_t time _ARG_((time_t *));
    extern int waitpid _ARG_((int, int *, int));

    extern void _exit _ARG_((int));

    typedef int (*Onexit_f) _ARG_((void));
    extern Onexit_f onexit _ARG_((Onexit_f));


    



    




    

    




    




     _END_EXTERNS_




#line 18 "graphviz-2.38.0\\lib\\sfio\\sfsetbuf.c" 2











/*	Set a (new) buffer for a stream.
**	If size < 0, it is assigned a suitable value depending on the
**	kind of stream. The actual buffer size allocated is dependent
**	on how much memory is available.
**
**	Written by Kiem-Phong Vo.
*/

    struct stat {
    int st_mode;
    int st_size;
};




Void_t *sfsetbuf(register Sfio_t * f, register Void_t * buf, register size_t size)






{
    register int sf_malloc;
    register unsigned char *obuf;
    register Sfdisc_t *disc;
    register ssize_t osize, blksize;
    register int oflags, init, local;

    

    Stat_t st;

    (void)(0);

    { if(!f) return(((Void_t *)0)); };

    ((local) = ((f)->mode&00100000), (f)->mode &= ~00100000, (local));

    if (size == 0 && buf) {	/* special case to get buffer info */
	_Sfi = f->val =
	    (f->bits & 00000001) ? (f->endb - f->data) : f->size;
	{ return((Void_t *) f->data); };
    }

    /* cleanup actions already done, don't allow write buffering any more */
    if ((_Sfextern.sf_exiting) && !(f->flags & 0000004) && (f->mode & 0000002)) {
	buf = ((Void_t *)0);
	size = 0;
    }

    if ((init = f->mode & 0000004)) {
	if (!f->pool && _sfsetpool(f) < 0)
	    { return(((Void_t *)0)); };
    } else if ((f->mode & (0000001|0000002)) != ((f)->mode & ~(00000020|00000010|((local) ? 00000040 : 0)) )
	       && _sfmode(f, 0, local) < 0)
	{ return(((Void_t *)0)); };

    if (init)
	f->mode = (f->mode & (0000001|0000002)) | 00000040;
    else {
	int rv;

	/* make sure there is no hidden read data */
	if (f->proc && (f->flags & 0000001) && (f->mode & 0000002) &&
	    _sfmode(f, 0000001, local) < 0)
	    { return(((Void_t *)0)); };

	/* synchronize first */
	(void)((f)->mode |= 00000040, (f)->endr = (f)->endw = (f)->data);
	rv = (((f)->mode |= 00100000),sfsync(f));
	(void)((local) ? 0 : ((f)->mode &= ~(00000040|00000010|00000020), ((f)->mode == 0000001 ? ((f)->endr = ((f)->flags&0) ? (f)->data : (f)->endb) : (f)->mode == 0000002 ? ((f)->endw = ((f)->flags&(0|0000040)) ? (f)->data : (f)->endb) : ((f)->endw = (f)->endr = (f)->data) ), 0) );
	if (rv < 0)
	    { return(((Void_t *)0)); };

	/* turn off the SF_SYNCED bit because buffer is changing */
	f->mode &= ~00004000;
    }

    (void)((f)->mode |= 00000040, (f)->endr = (f)->endw = (f)->data);

    blksize = 0;
    oflags = f->flags;


    
    
	      

    
    
	
	    
	    
	
    

    if (f->data == f->tiny) {
	f->data = ((unsigned char *)0);
	f->size = 0;
    }
    obuf = f->data;
    osize = f->size;

    f->flags &= ~0000020;
    f->bits &= ~00000001;

    /* pure read/string streams must have a valid string */
    if ((f->flags & ((0000001|0000002) | 0000004)) == (0000001|0000004) &&
	(size == (size_t) (-1) || !buf))
	size = 0;

    /* set disc to the first discipline with a seekf */
    for (disc = f->disc; disc; disc = disc->disc)
	if (disc->seekf)
	    break;

    if ((init || local) && !(f->flags & 0000004)) {	/* ASSERT(f->file >= 0) */
	st.st_mode = 0;

	/* if has discipline, set size by discipline if possible */
	if (!0 || disc) {
	    if ((f->here = (((f)->mode |= 00100000),sfsk(f,(_ast_intmax_t)(_ast_intmax_t) 0,1,disc))) < 0)
		goto unseekable;
	    else {
		_ast_intmax_t e;
		if ((e = (((f)->mode |= 00100000),sfsk(f,(_ast_intmax_t)(_ast_intmax_t) 0,2,disc))) >= 0)
		    f->extent = e > f->here ? e : f->here;
		(void) (((f)->mode |= 00100000),sfsk(f,(_ast_intmax_t)f->here,0,disc));
		goto setbuf;
	    }
	}

	/* get file descriptor status */
	if ((-1) < 0)
	    f->here = -1;
	else {

	    
		
		    


	    
		

	    if ((((st.st_mode)&0) == 0) || (((st.st_mode)&0) == 0))
		f->here = (((f)->mode |= 00100000),sfsk(f,(_ast_intmax_t)(_ast_intmax_t) 0,1,f->disc));
	    else
		f->here = -1;



	    
		
		


	}

	if (f->here >= 0) {
	    f->extent = (_ast_intmax_t) st.st_size;

	    /* seekable std-devices are share-public by default */
	    if (f == sfstdin || f == sfstdout || f == sfstderr)
		f->flags |= 0000100 | 0004000;
	} else {
	  unseekable:
	    f->extent = -1;
	    f->here = 0;

	    if (init) {
		if ((((st.st_mode)&0) == 0)) {
		    int oerrno = errno;

		    blksize = 1024;

		    /* set line mode for terminals */
		    if (!(f->flags & 0000040) && isatty(f->file))
			f->flags |= 0000040;

		    
			
			
			
			
			    
			    
			    
		    

		    errno = oerrno;
		}

		/* initialize side buffer for r+w unseekable streams */
		if (!f->proc && (f->bits & 00000002))
		    (void) _sfpopen(f, -1, -1, 0);
	    }
	}

	/* set page size, this is also the desired default buffer size */
	if ((_Sfextern.sf_page) <= 0) {

	    

		(_Sfextern.sf_page) = ((ssize_t)(1024*sizeof(int)*2));
	}
    }

    
	
	    
		
		    
	
	    
	    
		
		    
		
		    
		
		    
	    
	
    


    /* get buffer space */
  setbuf:
    if (size == (size_t) (-1)) {	/* define a default size suitable for block transfer */
	if (init && osize > 0)
	    size = osize;
	else if (f == sfstderr && (f->mode & 0000002))
	    size = 0;
	else if (f->flags & 0000004)
	    size = 1024;
	else if ((f->flags & 0000001) && !(f->bits & 00000002) &&
		 f->extent > 0 && f->extent < (_ast_intmax_t) (_Sfextern.sf_page))
	    size =
		(((size_t) f->extent + 1024 -
		  1) / 1024) * 1024;
	else if ((ssize_t) (size = (_Sfextern.sf_page)) < blksize)
	    size = blksize;

	buf = ((Void_t *)0);
    }

    sf_malloc = 0;
    if (size > 0 && !buf && !(f->bits & 00000001)) {	/* try to allocate a buffer */
	if (obuf && size == (size_t) osize && init) {
	    buf = (Void_t *) obuf;
	    obuf = ((unsigned char *)0);
	    sf_malloc = (oflags & 0000020);
	}
	if (!buf) {		/* do allocation */
	    while (!buf && size > 0) {
		if ((buf = (Void_t *) malloc(size)))
		    break;
		else
		    size /= 2;
	    }
	    if (size > 0)
		sf_malloc = 0000020;
	}
    }

    if (size == 0 && !(f->flags & 0000004) && !(f->bits & 00000001) && (f->mode & 0000001)) {	/* use the internal buffer */
	size = sizeof(f->tiny);
	buf = (Void_t *) f->tiny;
    }

    /* set up new buffer */
    f->size = size;
    f->next = f->data = f->endr = f->endw = (unsigned char *) buf;
    f->endb = (f->mode & 0000001) ? f->data : f->data + size;
    if (f->flags & 0000004) {	/* these fields are used to test actual size - see sfseek() */
	f->extent = (!sf_malloc &&
		     ((f->flags & 0000001)
		      || (f->bits & 00000002))) ? size : 0;
	f->here = 0;

	/* read+string stream should have all data available */
	if ((f->mode & 0000001) && !sf_malloc)
	    f->endb = f->data + size;
    }

    f->flags = (f->flags & ~0000020) | sf_malloc;

    if (obuf && obuf != f->data && osize > 0 && (oflags & 0000020)) {
	free((Void_t *) obuf);
	obuf = ((unsigned char *)0);
    }

    _Sfi = f->val = obuf ? osize : 0;

    (void)((local) ? 0 : ((f)->mode &= ~(00000040|00000010|00000020), ((f)->mode == 0000001 ? ((f)->endr = ((f)->flags&0) ? (f)->data : (f)->endb) : (f)->mode == 0000002 ? ((f)->endw = ((f)->flags&(0|0000040)) ? (f)->data : (f)->endb) : ((f)->endw = (f)->endr = (f)->data) ), 0) );

    { return((Void_t *) obuf); };
}
