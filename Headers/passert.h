#ifndef PASSERT_H
#define PASSERT_H

#ifdef  MAIN_FILE
int debug;
#else
extern int debug;
#endif


#define h_passert(expr) if (!(expr)&&debug) {fprintf(stderr, "Assertion failed. "#expr"\nExiting\n"); exit(1);}

#define s_passert(expr) if (!(expr)&&debug) {fprintf(stderr, "Assertion failed. "#expr"\n");}

#endif
