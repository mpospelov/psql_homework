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
#include <pgtypes_date.h>
/* exec sql begin declare section */ 
    
    
    

#line 6 "main.pgs"
 char connection_string [] = "rgr_db@127.0.0.1:5432" ;
 
#line 7 "main.pgs"
 char login [] = "postgres" ;
 
#line 8 "main.pgs"
 char password [] = "" ;
/* exec sql end declare section */
#line 9 "main.pgs"



const int string_size = 256;
const int text_size = 1024;

//для взаимодействия с БД
/* exec sql begin declare section */
 
   
   
   
    
   
   
 typedef struct { 
#line 18 "main.pgs"
 char field0 [ string_size ] ;
 
#line 19 "main.pgs"
 char field1 [ string_size ] ;
 
#line 20 "main.pgs"
 char field2 [ string_size ] ;
 
#line 21 "main.pgs"
 char field3 [ string_size ] ;
 
#line 22 "main.pgs"
 char field4 [ string_size ] ;
 
#line 23 "main.pgs"
 char field5 [ string_size ] ;
 }  cursor ;

#line 24 "main.pgs"

/* exec sql end declare section */
#line 25 "main.pgs"
	

void db_connect(){
  { ECPGconnect(__LINE__, 0, connection_string , login , password , NULL, 0); }
#line 28 "main.pgs"


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
#line 42 "main.pgs"

  printf("disconnect --OK\n");
}

void cursor_query(char *query, cursor *result){
  /* exec sql begin declare section */
     
     
  
#line 48 "main.pgs"
 cursor dbval ;
 
#line 49 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 50 "main.pgs"
	
  sprintf(stmt, "%s", query);
  printf("Executing query: %s\n", stmt);

  { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 54 "main.pgs"

  /* declare CursorQuery cursor for $1 */
#line 55 "main.pgs"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare CursorQuery cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 57 "main.pgs"

  /* exec sql whenever not found  break ; */
#line 58 "main.pgs"
  

  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch CursorQuery", ECPGt_EOIT, 
	ECPGt_char,&(dbval.field0),(long)string_size,(long)1,(string_size)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(dbval.field1),(long)string_size,(long)1,(string_size)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(dbval.field2),(long)string_size,(long)1,(string_size)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(dbval.field3),(long)string_size,(long)1,(string_size)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(dbval.field4),(long)string_size,(long)1,(string_size)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(dbval.field5),(long)string_size,(long)1,(string_size)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 62 "main.pgs"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 62 "main.pgs"

    *result = dbval;
    result ++;
  }

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close CursorQuery", ECPGt_EOIT, ECPGt_EORT);}
#line 67 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 68 "main.pgs"

  printf("Query Finished!\n");
}

void simple_query(char *query){
  /* exec sql begin declare section */
     
  
#line 74 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 75 "main.pgs"

  sprintf(stmt, "%s", query);
  printf("Executing query: %s\n", stmt);
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, stmt, ECPGt_EOIT, ECPGt_EORT);}
#line 78 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 79 "main.pgs"

  printf("Query Finished!\n");
}

