#include "file.h"
#define code1 0
#define code2 0
#define code3 1

#if code1 == 1
int main ()
{

}

#elif code2 == 1
int main ()
{

}

#elif code3 == 1
int main ()
{
#error "Main3 Error"
}

#endif
