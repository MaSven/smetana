package h;
import core.*;
import core.annotation.*;

// 13w4wtxe0z0sh446ur163yvhf

@TranslatedBy("plantuml")
public class gvplugin_active_layout_t extends Structure {
        public gvlayout_engine_t engine;
        public int id;
        public gvlayout_features_t features;
        public StarChar type;
        
        public void reset() {
        	engine = null;
        	id = 0;
        	features = null;
        	type = null;
        }
}

// typedef struct gvplugin_active_layout_s {
//         gvlayout_engine_t *engine;
//         int id;
//         gvlayout_features_t *features;
//         const char *type;
//     } gvplugin_active_layout_t;