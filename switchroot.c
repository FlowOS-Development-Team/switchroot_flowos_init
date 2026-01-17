#include <sys/mount.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    //Change directory to the sysroot
    chdir(argv[1]);

    // Move the mount point to the root of the filesystem
    mount(".", "/", NULL, MS_MOVE, NULL);

    //Change process root
    chroot(".");

    //Handoff to sysroot init
    execv(argv[2], &argv[2]);

    return 0;
}
