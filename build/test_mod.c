/* Processed by ecpg (4.8.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "main.pgs"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* exec sql begin declare section */ 
    
    
    

#line 6 "main.pgs"
 char ConnectionString [] = "tbd@127.0.0.1:5432" ;
 
#line 7 "main.pgs"
 char Login [] = "postgres" ;
 
#line 8 "main.pgs"
 char Password [] = "" ;
/* exec sql end declare section */
#line 9 "main.pgs"


void db_connect(){
  { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); }
#line 12 "main.pgs"


  if( sqlca.sqlcode != 0 || strncmp(sqlca.sqlstate,"00",2))
  {
    printf("connect -- NoOK\n");
    exit(-1);
  }
  else
  {
    printf("connect --OK\n");	
  }	
}

void db_disconnect(){
  { ECPGdisconnect(__LINE__, "CURRENT");}
#line 26 "main.pgs"

  printf("disconnect --OK\n");
}
