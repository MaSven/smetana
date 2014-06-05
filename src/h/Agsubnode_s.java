package h;
import core.*;
import core.annotation.*;

// eykrclzau59zmxissqegaiilg

@TranslatedBy("plantuml")
public class Agsubnode_s extends Structure {
    /* the node-per-graph-or-subgraph record */
    final public Dtlink_t seq_link = new Dtlink_t(this);		/* must be first */
    final public Dtlink_t id_link = new Dtlink_t();
    public Agnode_t node;		/* the object */
    public Dtlink_t in_id, out_id;	/* by node/ID for random access */
    public Dtlink_t in_seq, out_seq;	/* by node/sequence for serial access */
    
    public void reset() {
    	seq_link.reset();
    	id_link.reset();
    	node = null;
    	in_id = out_id = null;
    	in_seq = out_seq = null;
    }
	public StarVoid castTo(Class clazz) {
		if (clazz==Dtlink_t.class) {
			return seq_link;
		}
		return super.castTo(clazz);
	}
}

// struct Agsubnode_s {		/* the node-per-graph-or-subgraph record */
//     Dtlink_t seq_link;		/* must be first */
//     Dtlink_t id_link;
//     Agnode_t *node;		/* the object */
//     Dtlink_t *in_id, *out_id;	/* by node/ID for random access */
//     Dtlink_t *in_seq, *out_seq;	/* by node/sequence for serial access */
// };