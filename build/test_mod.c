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



void orm_select_values(char *table_name, cursor *result, char *condition ){

  /* exec sql begin declare section */
     
     
  
#line 51 "main.pgs"
 cursor dbval ;
 
#line 52 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 53 "main.pgs"
	

  sprintf(stmt, "SELECT * FROM %s WHERE %s", table_name, condition);

  { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 57 "main.pgs"

  /* declare SelectValuesCursor cursor for $1 */
#line 58 "main.pgs"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare SelectValuesCursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 60 "main.pgs"

  /* exec sql whenever not found  break ; */
#line 61 "main.pgs"
  

  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch SelectValuesCursor", ECPGt_EOIT, 
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
#line 65 "main.pgs"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 65 "main.pgs"

    *result = dbval;
    result++;
  }

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close SelectValuesCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 70 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 71 "main.pgs"

}

void orm_read_all_records(char *table_name, cursor *result){
  /* exec sql begin declare section */
     
     
  
#line 76 "main.pgs"
 cursor dbval ;
 
#line 77 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 78 "main.pgs"
	
  sprintf(stmt, "SELECT * FROM %s", table_name);

  { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 81 "main.pgs"

  /* declare ReadAllRecordCursor cursor for $1 */
#line 82 "main.pgs"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare ReadAllRecordCursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 84 "main.pgs"

  /* exec sql whenever not found  break ; */
#line 85 "main.pgs"
  

  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch ReadAllRecordCursor", ECPGt_EOIT, 
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
#line 89 "main.pgs"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 89 "main.pgs"

    *result = dbval;
    result ++;
  }

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close ReadAllRecordCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 94 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 95 "main.pgs"

}

void orm_update_values(char *table_name, char *condition, char *data){
  /* exec sql begin declare section */
     
  
#line 100 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 101 "main.pgs"

  sprintf(stmt, "UPDATE %s SET %s WHERE %s", table_name, data, condition);
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, stmt, ECPGt_EOIT, ECPGt_EORT);}
#line 103 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 104 "main.pgs"

}

void orm_insert_values(char *table_name, char *data){
  /* exec sql begin declare section */
     
  
#line 109 "main.pgs"
 char stmt [ text_size ] ;
/* exec sql end declare section */
#line 110 "main.pgs"

  sprintf(stmt, "INSERT INTO %s VALUES(%s)", table_name, data);
  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_exec_immediate, stmt, ECPGt_EOIT, ECPGt_EORT);}
#line 112 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 113 "main.pgs"
  
}
