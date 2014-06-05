package h;
import core.*;
import core.annotation.*;

// 6b881ar4wz3iwu5spghy0ocnj

@TranslatedBy("plantuml") 
public class _dtlink_s extends Structure {
	public Dtlink_t	right;	/* right child		*/
	
	public static class	hl extends Union {
		private @Unsigned int	_hash;	/* hash value		*/
	    private Dtlink_t	_left;	/* left child		*/
	    
	    public Dtlink_t _left() {
	    	return _left;
	    }
	    public Dtlink_t _left(Dtlink_t arg) {
	    	_left = arg;
	    	return _left;
	    }
	    
	    public void reset() {
	        _hash = 0;
	        _left = null;
	    }
	}
	
	public final hl hl = new hl();

	public void reset() {
	    right = null;	
	    hl.reset();
	}
	
	public _dtlink_s() {
		super();
	}
	public _dtlink_s(Object parentStructure) {
		super(parentStructure);
	}
}

// struct _dtlink_s
// {	Dtlink_t*	right;	/* right child		*/
// 	union
// 	{ unsigned int	_hash;	/* hash value		*/
// 	  Dtlink_t*	_left;	/* left child		*/
// 	} hl;
// };