package h;
import core.*;
import core.annotation.*;

// btpkmksp5qljd7s3c2whxtupr

@TranslatedBy("plantuml")
public class gvtextlayout_engine_s extends Structure {
    static public interface textlayout extends FP {
        boolean function(textspan_t span, StarStarChar fontpath);
    }
    public textlayout textlayout;
}

// struct gvtextlayout_engine_s {
// 	boolean (*textlayout) (textspan_t *span, char** fontpath);
//     };