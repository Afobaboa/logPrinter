# logPrinter


This program print logs for special file
which name is set in logPrinte.cpp defines.

If you use defined macroses like LOG_PRINT() almost
all log messages will be written with place 
where you print it and time when you print it. 


# Using


1. Clone repository
```git clone https://github.com/Afobaboa/logPrinter```

2. Include logPrinter.h like
```#include "logPrinter/logPrinter.h"```

3. Open and close log file in main.cpp and
print some logs in any source file like:

```int main()```

```{```

```LOG_OPEN();```

```...```

```LOG_PRINT(INFO, "Value = %d", value);```

```...```

```LOG_CLOSE();```

```return 0; ```

```}```


# Documentation


You can find documentation and some 
useful functions and defines in logPrinter.h.