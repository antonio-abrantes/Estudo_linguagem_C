#include <stdio.h>
#include <mysql.h>

int main(int argc, char **argv)
{
  MYSQL *conn = mysql_init(NULL);

  if (mysql_real_connect(conn, "localhost", "root", "eumesmo78", "twdata", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  char comando[500] = "Update pessoas Set id = 2 where nome = 'Antonio'";
  //if (mysql_query(conn, "CREATE DATABASE TWDATA"))
  //if (mysql_query(conn, "DROP DATABASE test"))
  if (mysql_query(conn, comando))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  mysql_close(conn);
  exit(0);
}
