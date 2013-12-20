#include "table_structs.h"
#ifdef __cplusplus
extern "C" {
#endif

  void db_connect();
  void db_disconnect();

  void cursor_query(char *query, cursor *result);
  void simple_query(char *query);
  

#ifdef __cplusplus
}
#endif
