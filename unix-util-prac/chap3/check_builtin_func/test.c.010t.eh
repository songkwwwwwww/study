
;; Function main (main, funcdef_no=0, decl_uid=2283, cgraph_uid=0, symbol_order=0)

main ()
{
  char buffer[10];
  int D.2287;

  __builtin_puts (&"test"[0]);
  __builtin_putchar (99);
  __builtin_memcpy (&buffer, "test", 5);
  D.2287 = 0;
  goto <D.2289>;
  <D.2289>:
  buffer = {CLOBBER};
  goto <D.2288>;
  D.2287 = 0;
  goto <D.2288>;
  <D.2288>:
  return D.2287;
}


