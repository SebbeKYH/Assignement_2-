#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// Defining the filename to be opened
const char* filename = "currencies.txt";

int main()
{
    // Open the file and read it...
    FILE *in_file = fopen(filename, "r");

    // Error handling
    if (!in_file)
    {
        perror("fopen");
        return 0;
    }

    // Function for reading and searching file.
    struct stat sb;
    if (stat(filename, &sb) == -1)
    {
        perror("stat");
        return 0;
    }

    //variabel f�r att scanna ord till file_contents
    char *file_contents = malloc(sb.st_size);

    // g�r igenom hela filen ord f�r ord
    while (fscanf(in_file, "%[^-\n ] ", file_contents) != EOF) {

     char *ptr;
     long ret;

     // h�mtar str om det �r en str, och siffra om det �r en siffra
     ret = strtol(file_contents, &ptr, 10);

    // om ret �r st�rre �n noll s� printar vi siffran och ny rad
      if (ret > 0)
      {
        printf("%s\n", file_contents);
        continue;
      }
      printf("%s ", file_contents);
      }

    fclose(in_file);

    return 0;
}


