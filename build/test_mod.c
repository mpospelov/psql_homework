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



//для взаимодействия с БД
/* exec sql begin declare section */
   
  
     
     
   typedef struct { 
#line 16 "main.pgs"
 int id ;
 
#line 17 "main.pgs"
 char name [ 256 ] ;
 }  dbinfo_t ;

#line 18 "main.pgs"


 
 
 
 

#line 20 "main.pgs"
 int my_id ;
 
#line 21 "main.pgs"
 char my_data [ 256 ] ;
 
#line 22 "main.pgs"
 int my_count ;
 
#line 23 "main.pgs"
 dbinfo_t dbval ;
/* exec sql end declare section */
#line 24 "main.pgs"
	

void db_connect(){
  { ECPGconnect(__LINE__, 0, ConnectionString , Login , Password , NULL, 0); }
#line 27 "main.pgs"


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
#line 41 "main.pgs"

  printf("disconnect --OK\n");
}

int orm_read_all_records(dbinfo_t *result)
{
  memset(&dbval, 0, sizeof(dbinfo_t));
  /* declare MyCursor cursor for select id , coalesce ( name , '' ) from exTab order by id */
#line 49 "main.pgs"

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for select id , coalesce ( name , '' ) from exTab order by id", ECPGt_EOIT, ECPGt_EORT);}
#line 50 "main.pgs"

  /* exec sql whenever not found  break ; */
#line 51 "main.pgs"
  
  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
	ECPGt_int,&(dbval.id),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(dbval.name),(long)256,(long)1,(256)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 54 "main.pgs"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 54 "main.pgs"

    *result = dbval;
    printf("C res: %d %s", dbval.id, dbval.name);
    result++;
  }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 59 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 60 "main.pgs"

  return 0;
}

