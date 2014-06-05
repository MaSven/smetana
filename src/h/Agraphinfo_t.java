package h;
import core.*;
import core.annotation.*;

// z6er5w4b36ot9sh8q7zz99ye

@TranslatedBy("plantuml")
public class Agraphinfo_t extends Structure {
	public StarVoid castTo(Class clazz) {
		if (clazz==Agrec_t.class) {
			return hdr;
		}
		return super.castTo(clazz);
	}
	
	public final Agrec_t hdr = new Agrec_t(this);
	/* to generate code */
	public layout_t drawing;
	public textlabel_t label;	/* if the cluster has a title */
	public final boxf bb = new boxf();			/* bounding box */
	public final pointf border[] = new pointf[]{new pointf(),new pointf(),new pointf(),new pointf()};	/* sizes of margins for graph labels */
	public @Unsigned char gui_state; /* Graph state for GUI ops */
	public @Unsigned char has_labels;
	public boolean has_images;
	public @Unsigned char charset; /* input character set */
	public int rankdir;
	public double ht1, ht2;	/* below and above extremal ranks */
	public @Unsigned int flags;
	public StarVoid alg;
	public GVC_t gvc;	/* context for "globals" over multiple graphs */

    static public interface cleanup extends FP {
        void function(Agraph_s arg1);
    }
    public cleanup cleanup;  /* function to deallocate layout-specific data */
    
	/* to have subgraphs */
	public int n_cluster;
	public StarStar<graph_t> clust;	/* clusters are in clust[1..n_cluster] !!! */
	public graph_t dotroot;
	public node_t nlist;
	public rank_t rank;
	public graph_t parent;        /* containing cluster (not parent subgraph) */
	public int level;		/* cluster nesting level (not node level!) */
	public node_t	minrep, maxrep;	/* set leaders for min and max rank */

	/* fast graph node list */
	public final nlist_t comp = new nlist_t();
	/* connected components */
	public node_t minset, maxset;	/* set leaders */
	public int n_nodes;
	/* includes virtual */
	public int minrank, maxrank;
	/* various flags */
	public boolean has_flat_edges;
	public boolean has_sourcerank;
	public boolean has_sinkrank;
	public @Unsigned char	showboxes;
	public fontname_kind fontnames;		/* to override mangling in SVG */
	public int nodesep, ranksep;
	public node_t ln, rn;	/* left, right nodes of bounding box */
	/* for clusters */
	public node_t leader;
	public StarStar<node_t> rankleader;
	public boolean expanded;
	public char installed;
	public char set_type;
	public char label_pos;
	public boolean exact_ranksep;
	
	public void reset() {
		hdr.reset();
		drawing = null;
		label = null;
		bb.reset();
		border[0].reset(); border[1].reset(); border[2].reset(); border[3].reset();
		gui_state = '\0';
		has_labels  = '\0';
		has_images = false;
		charset = '\0';
		rankdir = 0;
		ht1 = 0; ht2 = 0;
		flags = 0;
		alg = null;
		gvc = null;

		cleanup = null;
		
		n_cluster = 0;
		clust = null;
		dotroot = null;
		nlist = null;
		rank = null;
		parent = null;
		level = 0;
		minrep = null; maxrep = null;
		comp.reset();
		minset = maxset = null;
		n_nodes = 0;
		minrank = maxrank = 0;
		has_flat_edges = false;
		has_sourcerank = false;
		has_sinkrank = false;
		showboxes = '\0';
		fontnames = null;
		nodesep = ranksep = 0;
		ln = rn = null;
		leader = null;
		rankleader = null;
		expanded = false;
		installed = '\0';
		set_type = '\0';
		label_pos = '\0';
		exact_ranksep = false;
	}
}

// typedef struct Agraphinfo_t {
// 	Agrec_t hdr;
// 	/* to generate code */
// 	layout_t *drawing;
// 	textlabel_t *label;	/* if the cluster has a title */
// 	boxf bb;			/* bounding box */
// 	pointf border[4];	/* sizes of margins for graph labels */
// 	unsigned char gui_state; /* Graph state for GUI ops */
// 	unsigned char has_labels;
// 	boolean has_images;
// 	unsigned char charset; /* input character set */
// 	int rankdir;
// 	double ht1, ht2;	/* below and above extremal ranks */
// 	unsigned short flags;
// 	void *alg;
// 	GVC_t *gvc;	/* context for "globals" over multiple graphs */
// 	void (*cleanup) (graph_t * g);   /* function to deallocate layout-specific data */
// 
// 
// 	
// 	
// 	
// 	
// 	
// 	
// 
// 
// 	/* to have subgraphs */
// 	int n_cluster;
// 	graph_t **clust;	/* clusters are in clust[1..n_cluster] !!! */
// 	graph_t *dotroot;
// 	node_t *nlist;
// 	rank_t *rank;
// 	graph_t *parent;        /* containing cluster (not parent subgraph) */
// 	int level;		/* cluster nesting level (not node level!) */
// 	node_t	*minrep, *maxrep;	/* set leaders for min and max rank */
// 
// 	/* fast graph node list */
// 	nlist_t comp;
// 	/* connected components */
// 	node_t *minset, *maxset;	/* set leaders */
// 	long n_nodes;
// 	/* includes virtual */
// 	short minrank, maxrank;
// 
// 	/* various flags */
// 	boolean has_flat_edges;
// 	boolean has_sourcerank;
// 	boolean has_sinkrank;
// 	unsigned char	showboxes;
// 	fontname_kind fontnames;		/* to override mangling in SVG */
// 
// 	int nodesep, ranksep;
// 	node_t *ln, *rn;	/* left, right nodes of bounding box */
// 
// 	/* for clusters */
// 	node_t *leader, **rankleader;
// 	boolean expanded;
// 	char installed;
// 	char set_type;
// 	char label_pos;
// 	boolean exact_ranksep;
// 
// 
//     } Agraphinfo_t;