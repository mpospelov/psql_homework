#ifdef __cplusplus
extern "C" {
#endif

  void db_connect();
  void db_disconnect();
  void orm_read_all_records(int *ids, char *str);

#ifdef __cplusplus
}
#endif
