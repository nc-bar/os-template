#define VIDEO_MEM 0xb8000

void print_msg(void) {
    char *video = (char*) VIDEO_MEM;
    const char *msg = "kernel running";

    for(int i = 0; msg[i]; i++) {
        video[2*i] = msg[i];
        video[2*i + 1] = 0x07;
    }
}

void clear_screen() {
    int i;
    char *video = (char*) VIDEO_MEM; // screen memory

    for(i = 0; i < 25*80; i++) {
        video[2*i] = 0;
    }
}

void kernel_main(void) 
{
	clear_screen();
	print_msg();
}
