package h;
import core.*;
import core.annotation.*;

// 3xlydw5hu2becv89l6tup8eo

@TranslatedBy("plantuml") 
public class GVCOMMON_t extends Structure {
	public StarStarChar info;
	public StarChar cmdname;
	public boolean verbose;
	public boolean config, auto_outfile_names;
	public static interface errorfn extends FP {
		public void function(StarChar fmt, Object... arg);
	}
	public errorfn errorfn;
	public StarStarChar show_boxes; /* emit code for correct box coordinates */
	public StarStarChar lib; 

	/* rendering state */
	public int viewNum;     /* current view - 1 based count of views,
			    all pages in all layers */
	public lt_symlist_t builtins;
	public boolean demand_loading;
	
	public GVCOMMON_t(Structure parent) {
		super(parent);
	}
	public void reset() {
		info = null;
		cmdname = null;
		verbose = false;
		config = false; auto_outfile_names = false;
		errorfn = null;
		show_boxes = null;
		lib = null;
		viewNum = 0;
		builtins = null;
		demand_loading = false;
	}
	
}

// typedef struct GVCOMMON_s {
// 	char **info;
// 	char *cmdname;
// 	int verbose;
// 	boolean config, auto_outfile_names;
//         void (*errorfn) (const char *fmt, ...);
// 	const char **show_boxes; /* emit code for correct box coordinates */
// 	const char **lib; 
// 
// 	/* rendering state */
// 	int viewNum;     /* current view - 1 based count of views,
// 			    all pages in all layers */
// 	const lt_symlist_t *builtins;
// 	int demand_loading;
//     } GVCOMMON_t;