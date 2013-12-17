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
#line 20 "main.pgs"
 char name [ string_size ] ;
 
#line 21 "main.pgs"
 char title [ string_size ] ;
 
#line 22 "main.pgs"
 char post [ string_size ] ;
 }  teacher ;

#line 23 "main.pgs"


 

   
   
   
   
 typedef struct { 
#line 27 "main.pgs"
 char student_name [ string_size ] ;
 
#line 28 "main.pgs"
 char teacher_name [ string_size ] ;
 
#line 29 "main.pgs"
 char theme [ string_size ] ;
 
#line 30 "main.pgs"
 char type [ string_size ] ;
 }  scientific_managment ;

#line 31 "main.pgs"


 

 

   
   
 typedef struct { 
#line 37 "main.pgs"
 char achivement_name [ string_size ] ;
 
#line 38 "main.pgs"
 char teacher_name [ string_size ] ;
 }  achivements_teachers ;

#line 39 "main.pgs"


 

 
   
   
   
    
 typedef struct { 
#line 44 "main.pgs"
 char name [ string_size ] ;
 
#line 45 "main.pgs"
 char description [ text_size ] ;
 
#line 46 "main.pgs"
 bool topicality ;
 
#line 47 "main.pgs"
 date date ;
 }  achivement ;

#line 48 "main.pgs"


 

 
   
   
 typedef struct { 
#line 53 "main.pgs"
 char achivement_name [ string_size ] ;
 
#line 54 "main.pgs"
 char teacher_name [ string_size ] ;
 }  authorship ;

#line 55 "main.pgs"


 

 
   
   
   
   
   
typedef struct { 
#line 60 "main.pgs"
 char name [ string_size ] ;
 
#line 61 "main.pgs"
 int page_count ;
 
#line 62 "main.pgs"
 char house [ string_size ] ;
 
#line 63 "main.pgs"
 char circulation [ string_size ] ;
 
#line 64 "main.pgs"
 date date ;
 }  publication ;

#line 65 "main.pgs"



 

 
   
   
   
 typedef struct { 
#line 71 "main.pgs"
 date conference_date ;
 
#line 72 "main.pgs"
 char teacher_name [ string_size ] ;
 
#line 73 "main.pgs"
 char conference_theme [ string_size ] ;
 }  conferences_teachers ;

#line 74 "main.pgs"


 

 
   
   
   
   
typedef struct { 
#line 79 "main.pgs"
 date date ;
 
#line 80 "main.pgs"
 char theme [ string_size ] ;
 
#line 81 "main.pgs"
 char place [ string_size ] ;
 
#line 82 "main.pgs"
 char type [ string_size ] ;
 }  conference ;

#line 83 "main.pgs"


 

 
   
   
typedef struct { 
#line 88 "main.pgs"
 char teacher_name [ string_size ] ;
 
#line 89 "main.pgs"
 int discipline_id ;
 }  disciplines_teachers ;

#line 90 "main.pgs"


 

 
   
   
   
typedef struct { 
#line 95 "main.pgs"
 int id ;
 
#line 96 "main.pgs"
 int hours ;
 
#line 97 "main.pgs"
 char name [ string_size ] ;
 }  discipline ;

#line 98 "main.pgs"


 
   
   
   
    
   
   
 typedef struct { 
#line 101 "main.pgs"
 char field0 [ string_size ] ;
 
#line 102 "main.pgs"
 char field1 [ string_size ] ;
 
#line 103 "main.pgs"
 char field2 [ string_size ] ;
 
#line 104 "main.pgs"
 char field3 [ string_size ] ;
 
#line 105 "main.pgs"
 char field4 [ string_size ] ;
 
#line 106 "main.pgs"
 char field5 [ string_size ] ;
 }  cursor ;

#line 107 "main.pgs"

 


#line 33 "main.pgs"
 scientific_managment sql_scientific_managment ;
 
#line 41 "main.pgs"
 achivements_teachers sql_achivements_teachers ;
 
#line 50 "main.pgs"
 achivement sql_achivement ;
 
#line 57 "main.pgs"
 authorship sql_authorship ;
 
#line 68 "main.pgs"
 publication sql_publication ;
 
#line 76 "main.pgs"
 conferences_teachers sql_conferences_teachers ;
 
#line 85 "main.pgs"
 conference sql_conference ;
 
#line 92 "main.pgs"
 disciplines_teachers sql_disciplines_teachers ;
 
#line 108 "main.pgs"
 discipline sql_discipline ;
/* exec sql end declare section */
#line 110 "main.pgs"
	

void db_connect(){
  { ECPGconnect(__LINE__, 0, connection_string , login , password , NULL, 0); }
#line 113 "main.pgs"


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
#line 127 "main.pgs"

  printf("disconnect --OK\n");
}


int orm_read_all_records(char *table_name, cursor *result){
  /* exec sql begin declare section */
     
     
  
#line 134 "main.pgs"
 cursor dbval ;
 
#line 135 "main.pgs"
 char stmt [ string_size ] ;
/* exec sql end declare section */
#line 136 "main.pgs"
	
  sprintf(stmt, "SELECT * FROM %s", table_name);

  { ECPGprepare(__LINE__, NULL, 0, "sqlstmt", stmt);}
#line 139 "main.pgs"

  /* declare MyCursor cursor for $1 */
#line 140 "main.pgs"


  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare MyCursor cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "sqlstmt", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 142 "main.pgs"

  /* exec sql whenever not found  break ; */
#line 143 "main.pgs"
  

  while(1)
  {
    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch MyCursor", ECPGt_EOIT, 
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
#line 147 "main.pgs"

if (sqlca.sqlcode == ECPG_NOT_FOUND) break;}
#line 147 "main.pgs"

    *result = dbval;
    result ++;
  }

  { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close MyCursor", ECPGt_EOIT, ECPGt_EORT);}
#line 152 "main.pgs"

  { ECPGtrans(__LINE__, NULL, "commit");}
#line 153 "main.pgs"

  return 0;
}
