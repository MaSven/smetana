package h;
import core.*;
import core.annotation.*;

// dg8cqsmppn0zl04sycueci9yw

@TranslatedBy("plantuml")
public class GVJ_s extends Structure {
	public GVC_t gvc;		/* parent gvc */
	public GVJ_t next;		/* linked list of jobs */
	public GVJ_t next_active;	/* linked list of active jobs (e.g. multiple windows) */
	public GVCOMMON_t common;
	public obj_state_t obj;	/* objects can be nested (at least clusters can)
					so keep object state on a stack */
	public StarChar input_filename;
	public int graph_index;
	public StarChar layout_type;
	public StarChar output_filename;
	public java.io.File output_file;
	public StarChar output_data;
	public @Unsigned int output_data_allocated;
	public @Unsigned int output_data_position;
	public StarChar output_langname;
	public int output_lang;
	public final gvplugin_active_render_t render = new gvplugin_active_render_t();
	public final gvplugin_active_device_t device = new gvplugin_active_device_t();
	public final gvplugin_active_loadimage_t loadimage = new gvplugin_active_loadimage_t();
	public gvdevice_callbacks_t callbacks;
	public final pointf device_dpi = new pointf();
	public boolean device_sets_dpi;
	public StarVoid display;
	public int screen;
	public StarVoid context;		/* gd or cairo surface */
	public boolean external_context;	/* context belongs to caller */
	public StarChar imagedata;	/* location of imagedata */
    public int flags;		/* emit_graph flags */
	public int numLayers;		/* number of layers */
	public int layerNum;		/* current layer - 1 based*/
	public final point 	pagesArraySize = new point(); /* 2D size of page array */
	public final point	pagesArrayFirst = new point();/* 2D starting corner in */
	public final point	pagesArrayMajor = new point();/* 2D major increment */
	public final point	pagesArrayMinor = new point();/* 2D minor increment */
	public final point	pagesArrayElem = new point(); /* 2D coord of current page - 0,0 based */
    public int	numPages;	/* number of pages */
	public final boxf    bb = new boxf();		/* graph bb with padding - graph units */
	public final pointf  pad = new pointf();		/* padding around bb - graph units */
	public final boxf    clip = new boxf();		/* clip region in graph units */
	public final boxf	pageBox = new boxf();	/* current page in graph units */
	public final pointf	pageSize = new pointf();	/* page size in graph units */
	public final pointf  focus = new pointf();		/* viewport focus - graph units */
	public double  zoom;		/* viewport zoom factor (points per graph unit) */
	public int	rotation;	/* viewport rotation (degrees)  0=portrait, 90=landscape */
	public final pointf  view = new pointf();		/* viewport size - points */
	public final boxf	canvasBox = new boxf();	/* viewport area - points */
        public final pointf  margin = new pointf();		/* job-specific margin - points */
	public final pointf	dpi = new pointf();		/* device resolution device-units-per-inch */
        public @Unsigned int width;     /* device width - device units */
        public @Unsigned int height;    /* device height - device units */
	public final box     pageBoundingBox = new box();/* rotated boundingBox - device units */
	public final box     boundingBox = new box();    /* cumulative boundingBox over all pages - device units */
	public final pointf  scale = new pointf();		/* composite device to graph units (zoom and dpi) */
	public final pointf  translation = new pointf();    /* composite translation */
	public final pointf  devscale = new pointf();	/* composite device to points: dpi, y_goes_down */
	public boolean	fit_mode,
		needs_refresh,
		click,
		has_grown,
		has_been_rendered;
	public @Unsigned char button;   /* active button */
	public pointf pointer = new pointf();		/* pointer position in device units */
	public pointf oldpointer = new pointf();	/* old pointer position in device units */
	public StarVoid current_obj;      /* graph object that pointer is in currently */
	public StarVoid selected_obj;      /* graph object that has been selected */
					/* (e.g. button 1 clicked on current obj) */
	public StarChar active_tooltip;		/* tooltip of active object - or NULL */
	public StarChar selected_href;		/* href of selected object - or NULL */
	//gv_argvlist_t selected_obj_type_name; /* (e.g. "edge" "node3" "e" "->" "node5" "") */
	//gv_argvlist_t selected_obj_attributes; /* attribute triplets: name, value, type */
				/* e.g. "color", "red", GVATTR_COLOR,
					"style", "filled", GVATTR_BOOL, */
	public StarVoid window;		/* display-specific data for gvrender plugin */
        /* keybindings for keyboard events */
	public gvevent_key_binding_t keybindings;
	public int numkeys;
	public StarVoid keycodes;
	
	public void reset() {
	gvc = null;
	next = null;
	next_active = null;
	common = null;
	obj = null;
	input_filename = null;
	graph_index = 0;
	layout_type = null;
	output_filename = null;
	output_file = null;
	output_data = null;
	output_data_allocated = 0;
	output_data_position = 0;
	output_langname = null;
	output_lang = 0;
	render.reset();
	device.reset();
	loadimage.reset();
	callbacks = null;
	device_dpi.reset();
	device_sets_dpi = false;
	display = null;
	screen = 0;
	context = null;
	external_context = false;
	imagedata = null;
    flags = 0;
	numLayers = 0;
	layerNum = 0;
	pagesArraySize.reset();
	pagesArrayFirst.reset();
	pagesArrayMajor.reset();
	pagesArrayMinor.reset();
	pagesArrayElem.reset();
    numPages = 0;
	bb.reset();
	pad.reset();
	clip.reset();
	pageBox.reset();
	pageSize.reset();
	focus.reset();
	zoom = 0;
	rotation = 0;
	view.reset();
	canvasBox.reset();
    margin.reset();
	dpi.reset();
    width = 0;
    height = 0;
	pageBoundingBox.reset();
	boundingBox.reset();
	scale.reset();
	translation.reset();
	devscale.reset();
	fit_mode = false;
		needs_refresh = false;
		click = false;
		has_grown = false;
		has_been_rendered = false;
	button = '\0';
	pointer.reset();
	oldpointer.reset();
	current_obj = null;
	selected_obj = null;
	active_tooltip = null;
	selected_href = null;
	//gv_argvlist_t selected_obj_type_name;
	//gv_argvlist_t selected_obj_attributes;
	window = null;
	keybindings = null;
	numkeys = 0;
	keycodes = null;

	}

}

// struct GVJ_s {
// 	GVC_t *gvc;		/* parent gvc */
// 	GVJ_t *next;		/* linked list of jobs */
// 	GVJ_t *next_active;	/* linked list of active jobs (e.g. multiple windows) */
// 
// 	GVCOMMON_t *common;
// 
// 	obj_state_t *obj;	/* objects can be nested (at least clusters can)
// 					so keep object state on a stack */
// 	char *input_filename;
// 	int graph_index;
// 
// 	const char *layout_type;
// 
// 	const char *output_filename;
// 	FILE *output_file;
// 	char *output_data;
// 	unsigned int output_data_allocated;
// 	unsigned int output_data_position;
// 
// 	const char *output_langname;
// 	int output_lang;
// 
// 	gvplugin_active_render_t render;
// 	gvplugin_active_device_t device;
// 	gvplugin_active_loadimage_t loadimage;
// 	gvdevice_callbacks_t *callbacks;
// 	pointf device_dpi;
// 	boolean device_sets_dpi;
// 
// 	void *display;
// 	int screen;
// 
// 	void *context;		/* gd or cairo surface */
// 	boolean external_context;	/* context belongs to caller */
// 	char *imagedata;	/* location of imagedata */
// 
//         int flags;		/* emit_graph flags */
// 
// 	int numLayers;		/* number of layers */
// 	int layerNum;		/* current layer - 1 based*/
// 
// 	point 	pagesArraySize; /* 2D size of page array */
// 	point	pagesArrayFirst;/* 2D starting corner in */
// 	point	pagesArrayMajor;/* 2D major increment */
// 	point	pagesArrayMinor;/* 2D minor increment */
// 	point	pagesArrayElem; /* 2D coord of current page - 0,0 based */
//         int	numPages;	/* number of pages */
// 
// 	boxf    bb;		/* graph bb with padding - graph units */
// 	pointf  pad;		/* padding around bb - graph units */
// 	boxf    clip;		/* clip region in graph units */
// 	boxf	pageBox;	/* current page in graph units */
// 	pointf	pageSize;	/* page size in graph units */
// 	pointf  focus;		/* viewport focus - graph units */
// 
// 	double  zoom;		/* viewport zoom factor (points per graph unit) */
// 	int	rotation;	/* viewport rotation (degrees)  0=portrait, 90=landscape */
// 
// 	pointf  view;		/* viewport size - points */
// 	boxf	canvasBox;	/* viewport area - points */
//         pointf  margin;		/* job-specific margin - points */
// 
// 	pointf	dpi;		/* device resolution device-units-per-inch */
// 
//         unsigned int width;     /* device width - device units */
//         unsigned int height;    /* device height - device units */
// 	box     pageBoundingBox;/* rotated boundingBox - device units */
// 	box     boundingBox;    /* cumulative boundingBox over all pages - device units */
// 
// 	pointf  scale;		/* composite device to graph units (zoom and dpi) */
// 	pointf  translation;    /* composite translation */
// 	pointf  devscale;	/* composite device to points: dpi, y_goes_down */
// 
// 	boolean	fit_mode,
// 		needs_refresh,
// 		click,
// 		has_grown,
// 		has_been_rendered;
// 
// 	unsigned char button;   /* active button */
// 	pointf pointer;		/* pointer position in device units */
// 	pointf oldpointer;	/* old pointer position in device units */
// 
// 	void *current_obj;      /* graph object that pointer is in currently */
// 
// 	void *selected_obj;      /* graph object that has been selected */
// 					/* (e.g. button 1 clicked on current obj) */
// 	char *active_tooltip;		/* tooltip of active object - or NULL */
// 	char *selected_href;		/* href of selected object - or NULL */
// 	gv_argvlist_t selected_obj_type_name; /* (e.g. "edge" "node3" "e" "->" "node5" "") */
// 	gv_argvlist_t selected_obj_attributes; /* attribute triplets: name, value, type */
// 				/* e.g. "color", "red", GVATTR_COLOR,
// 					"style", "filled", GVATTR_BOOL, */
// 
// 	void *window;		/* display-specific data for gvrender plugin */
// 
//         /* keybindings for keyboard events */
// 	gvevent_key_binding_t *keybindings;
// 	int numkeys;
// 	void *keycodes;
//     };