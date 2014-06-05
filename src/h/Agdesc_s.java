package h;
import core.*;
import core.annotation.*;

// drqmj6wswekevi9i4ghve61wj

@TranslatedBy("plantuml")
public class Agdesc_s extends Structure {
	public boolean directed; /* if edges are asymmetric */
	public boolean strict; /* if multi-edges forbidden */
	public boolean no_loop; /* if no loops */
	public boolean maingraph; /* if this is the top level graph */
	public boolean flatlock; /* if sets are flattened into lists in cdt */
	public boolean no_write; /* if a temporary subgraph */
	public boolean has_attrs; /* if string attr tables should be initialized */
	public boolean has_cmpnd; /* if may contain collapsed nodes */
	
	public void reset() {
	    directed = strict = no_loop = maingraph = flatlock = no_write = has_attrs = has_cmpnd = false;
	}

	public void memcopyFrom(StarVoid from) {
		final Agdesc_s from2 = (Agdesc_s) from;
		this.directed = from2.directed;
		this.strict = from2.strict;
		this.no_loop = from2.no_loop;
		this.maingraph = from2.maingraph;
		this.flatlock = from2.flatlock;
		this.no_write = from2.no_write;
		this.has_attrs = from2.has_attrs;
		this.has_cmpnd = from2.has_cmpnd;
	}
}

// struct Agdesc_s {		/* graph descriptor */
//     unsigned directed:1;	/* if edges are asymmetric */
//     unsigned strict:1;		/* if multi-edges forbidden */
//     unsigned no_loop:1;		/* if no loops */
//     unsigned maingraph:1;	/* if this is the top level graph */
//     unsigned flatlock:1;	/* if sets are flattened into lists in cdt */
//     unsigned no_write:1;	/* if a temporary subgraph */
//     unsigned has_attrs:1;	/* if string attr tables should be initialized */
//     unsigned has_cmpnd:1;	/* if may contain collapsed nodes */
// };