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
 char connection_string [] = "nastya_rgr@127.0.0.1:5432" ;
 
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
#line 17 "main.pgs"
 char field0 [ string_size ] ;
 
#line 18 "main.pgs"
 char field1 [ string_size ] ;
 
#line 19 "main.pgs"
 char field2 [ string_size ] ;
 
#line 20 "main.pgs"
 char field3 [ string_size ] ;
 
#line 21 "main.pgs"
 char field4 [ string_size ] ;
 
#line 22 "main.pgs"
 char field5 [ string_size ] ;
 }  cursor ;

#line 23 "main.pgs"

/* exec sql end declare section */
#line 24 "main.pgs"
	

void db_connect(){
  { ECPGconnect(__LINE__, 0, connection_string , login , password , NULL, 0); }
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

bool handle_errors(){
  if (sqlca.sqlcode != ECPG_NO_ERROR &&
      sqlca.sqlcode != ECPG_NOT_FOUND &&
      sqlca.sqlcode != ECPG_TOO_MANY_ARGUMENTS){
    printf("%s\n",sqlca.sqlerrm.sqlerrmc);
    return true;
  }else{
    return false;
  }
}
void cursor_query(char *query, cursor *result){
  /* exec sql begin declare section */
     
     
  
#line 57 "main.pgs"
 cursor dbval ;
 
#line 58 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 59 "main.pgs"
	
  sprintf(stmt, "%s", query);
  printf("Executing query: %s\n", stmt);

  { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 63 "main.pgs"

  /* declare CursorQuery cursor for $1 */
#line 64 "main.pgs"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare CursorQuery cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 66 "main.pgs"

  /* exec sql whenever not found  break ; */
#line 67 "main.pgs"
  

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
#line 71 "main.pgs"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 71 "main.pgs"

    if(handle_errors()) break;
    *result = dbval;
    result ++;
  }
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close CursorQuery", ECPGt_EOIT, ECPGt_EORT);}
#line 76 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 77 "main.pgs"

  printf("Query Finished!\n");
}

void simple_query(char *query){
  /* exec sql begin declare section */
     
  
#line 83 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 84 "main.pgs"

  sprintf(stmt, "%s", query);
  printf("Executing query: %s\n", stmt);
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, stmt, ECPGt_EOIT, ECPGt_EORT);}
#line 87 "main.pgs"

  handle_errors();
  { ECPGtrans(__LINE__, NULL, "commit");}
#line 89 "main.pgs"

  printf("Query Finished!\n");
}

