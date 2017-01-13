
;; Function main (main, funcdef_no=23, decl_uid=2480, cgraph_uid=23, symbol_order=23)

main ()
{
  int k;
  int j;
  int i;
  int D.2494;
  unsigned int D.2490;
  unsigned int i.0;

  j = 0;
  k = 0;
  i = 0;
  goto <D.2486>;
  <D.2485>:
  i.0 = (unsigned int) i;
  D.2490 = i.0 & 1;
  if (D.2490 != 0) goto <D.2491>; else goto <D.2492>;
  <D.2491>:
  j = j + 1;
  goto <D.2493>;
  <D.2492>:
  k = k + 1;
  <D.2493>:
  printf ("j = %d, k = %d\n", j, k);
  i = i + 1;
  <D.2486>:
  if (i <= 9) goto <D.2485>; else goto <D.2487>;
  <D.2487>:
  D.2494 = 0;
  goto <D.2495>;
  D.2494 = 0;
  goto <D.2495>;
  <D.2495>:
  return D.2494;
}



;; Function printf (<unset-asm-name>, funcdef_no=15, decl_uid=760, cgraph_uid=15, symbol_order=15)

printf (const char * restrict __fmt)
{
  int D.2496;

  D.2496 = __printf_chk (1, __fmt, __builtin_va_arg_pack ());
  goto <D.2497>;
  <D.2497>:
  return D.2496;
}


