#include "table_structs.h"
#ifdef __cplusplus
extern "C" {
#endif

  void db_connect();
  void db_disconnect();
  void orm_read_all_records(dbinfo_t *result);

#ifdef __cplusplus
}
#endif
