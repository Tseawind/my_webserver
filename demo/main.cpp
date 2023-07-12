#include <unistd.h>
#include "../server/webserver.h"

int main()
{
    WebServer server(
        6666, 3, 60000, true,
        3306, "feng", "123", "server",
        12, 6, true, 1, 1024);
    server.Start();
}