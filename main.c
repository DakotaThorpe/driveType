/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <sys/types.h>

struct test {
    int version;
    int fileCount;
    int usedSpace;
    int freeSpace;
    int sectorSize;
    char hostOs[32];
    char driveName[32];
};
typedef struct test DriveHeader;
int main()
{
    DriveHeader dhead = {
        1,
        0,
        0,
        10000,
        512,
        "CHROMEOS",
        "A:"
    };
    
    DriveHeader din;
    
    FILE* out;
    FILE* in;
    out = fopen("test.bin", "wb");
    in = fopen("test.bin", "rb");
    fwrite(&dhead, 1, sizeof(dhead), out);
    fclose(out);
    fread(&din, 1, sizeof(din), in);
    fclose(in);
    
    printf("Drive has a capacity of %d bytes with %d used.\n", din.freeSpace, din.usedSpace);
    printf("Disk info: %d sector size, %d files.\n", din.sectorSize, din.fileCount);
    printf("%s(%s)>\n", din.driveName, din.hostOs);

    return 0;
}
