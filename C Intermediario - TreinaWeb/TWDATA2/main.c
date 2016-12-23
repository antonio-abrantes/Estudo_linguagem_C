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

  /*if (mysql_query(conn, "CREATE TABLE Cachorro(id int primary key auto_increment,nome text, raca text)"))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  if (mysql_query(conn, "INSERT INTO Cachorro(nome,raca)VALUES ('toto','vira lata')"))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  if (mysql_query(conn, "INSERT INTO Cachorro(nome,raca)VALUES ('zeus','doberman')"))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  if (mysql_query(conn, "INSERT INTO Cachorro(nome,raca)VALUES ('duke','pastor alemao')"))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  if (mysql_query(conn, "INSERT INTO Cachorro(nome,raca)VALUES ('fifi','poodle')"))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }*/

  if (mysql_query(conn, "SELECT * FROM cachorro"))
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

   MYSQL_RES *result = mysql_store_result(conn);

  if (result == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(conn));
      mysql_close(conn);
      exit(1);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  int i;

  while ((row = mysql_fetch_row(result)))
  {
      for(i = 0; i < num_fields; i++)
      {
          printf("%s ", row[i] ? row[i] : "NULL");
      }
          printf("\n");
  }

  mysql_free_result(result);

  mysql_close(conn);
  exit(0);
}
