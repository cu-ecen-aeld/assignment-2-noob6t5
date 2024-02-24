#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
//Prototype
void writeToLogFile(const char *nameofFile, const char *content);
void writeToLogFile(const char *nameofFile, const char *content)
{
    FILE *file = fopen(nameofFile, "w");
    if (file != NULL)
    {
        fputs(content, file);
        fclose(file);
        syslog(LOG_DEBUG, "Writing \"%s\" to %s", content, nameofFile);
    }
    else
    {
        syslog(LOG_ERR, "Failed to open file %s", nameofFile);
    }
}

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    if (argc != 3)
    {
        syslog(LOG_ERR, "Please Follow this : %s <filename> <content>", argv[0]);
        closelog();
        return EXIT_FAILURE;
    }
    const char *nameofFile = argv[1];
    const char *content = argv[2];
    writeToLogFile(nameofFile, content);
    closelog();
    return EXIT_SUCCESS;
}
