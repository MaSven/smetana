package h;
import core.*;
import core.annotation.*;

// 2nxdbvy3uxd7hzq9yspewhiy2

@TranslatedBy("plantuml") 
public class Agdesc_t extends Agdesc_s {
	public Agdesc_t(int directed, int strict, int no_loop, int maingraph, int flatlock, int no_write) {
		this.directed = directed !=0;
		this.strict = strict !=0;
		this.no_loop = no_loop !=0;
		this.maingraph = maingraph !=0;
		this.flatlock = flatlock !=0;
		this.no_write = no_write !=0;
	}
	public Agdesc_t() {
	}
	
}

// typedef struct Agdesc_s Agdesc_t;