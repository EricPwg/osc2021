# include "user_lib.h"

//itoa
void int_to_str(int n, char *s){
  int nt = (n < 0) ? -n : n;
  char tmp[100];
  int idx = 0;
  do{
    tmp[idx] = (char)((nt%10) + 48);
    idx++;
    nt /= 10;
  } while(nt > 0);
  if (n < 0){
    tmp[idx] = '-';
    idx++;
  }
  for (int i=0; i<idx; i++){
    s[i] = tmp[idx-i-1];
  }
  s[idx] = '\0';
}

void int_to_hex_align(unsigned long long n, char *s, int len){
  int idx = len;
  do{
    unsigned long long t = n%16;
    if (t < 10)
      s[idx] = (char)(t + 48);
    else
      s[idx] = (char)(t + 87);
    idx--;
    n /= 16;
  } while(n > 0);
  s[idx--] = 'x';
  s[idx--] = '0';
  while(idx >= 0){
    s[idx--] = ' ';
  }
}

void int_to_hex(unsigned long long n, char *s){
  char tmp[100];
  int idx = 0;
  do{
    unsigned long t = n%16;
    if (t < 10)
      tmp[idx] = (char)(t + 48);
    else
      tmp[idx] = (char)(t + 87);
    idx++;
    n /= 16;
  } while(n > 0);
  tmp[idx++] = 'x';
  tmp[idx++] = '0';
  for (int i=0; i<idx; i++){
    s[i] = tmp[idx-i-1];
  }
  s[idx] = '\0';
}

void ptr_to_hex(void *p, char *s){
  unsigned long long a = (unsigned long long) p;
  int_to_hex(a, s);
}

unsigned long hex_to_uint(char *s, int l){
  unsigned long r = 0;
  for (int i=0; i<l; i++){
    if (s[i] >= 'a') s[i] = s[i] -(char)32;
    if (s[i] >= 'A') r = r*16+( (unsigned long)s[i] - 55);
    else r = r*16+( (unsigned long)s[i] - 48);
  }
  return r;
}

int str_to_int(char *c){
  int r = 0;
  while(*c){
    r = r*10+(*c)-'0';
    c++;
  }
  return r;
}

int round_up(int n, int a){
  int r = n/a;
  return (n%a) ? r+1 : r;
}

int align_up(int n, int a){
  if (n%a == 0) return n;
  return (n/a+1)*a;
}

void delay(int p){
  while(p--);
}

int str_cmp(const char *s1, const char *s2){
  int i = 0;
  if (s1[0] == '\0' && s2[0] == '\0'){
    return 1;
  }
  while(s1[i]){
    if (s1[i] != s2[i]) return 0;
    i++;
  }

  if (s2[i] == '\0') return 1;
  return 0;
}

int str_len(const char *s){
  int r = 0;
  while(*s++){
    r++;
  }
  return r;
}

void str_copy(const char *src, char *target){
  while(1){
    *target = *src;
    if (*src){
      src++;
      target++;
    }
    else{
      break;
    }
  }
}

void assert(bool t, const char *c){
  if (!t){
    uart_write((char *) "[ASSERT] ", 9);
    uart_write(c, str_len(c));
    uart_write((char *) "\n", 1);
    exit();
  }
}
