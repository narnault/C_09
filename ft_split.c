#include <stdlib.h>
#include <stdio.h>

int             is_charset(char c, char *charset) {

        int i;

        i = -1;
        while (charset[++i]) {

                if (c == charset[i])
                        return (1);
        }
        return (0);
}

int             count(char *str, char *charset) {

        int i;
        int j;

        i = 0;
        j = 0;
        while (str[i]) {

                while (is_charset(str[i], charset) && str[i])
                        i++;
                if (!str[i])
                        break ;
                while (is_charset(str[i], charset) == 0 && str[i])
                        i++;
                j++;
        }
        return (j);
}

char    *cpy(char *dest, char *src, int k, int j) {

        int i;

        i = 0;
        while (k < j)
        {
                dest[i] = src[k];
                k++;
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

int             get_strings(char **src, char *str, char *charset) {

        int i;
        int j;
        int k;
        int nb;

        nb = 0;
        i = -1;
        while (str[++i]) {

                j = 0;
                while (is_charset(str[i], charset) && str[i])
                        i++;
                k = i;
                while (is_charset(str[i], charset) == 0 && str[i])
                        i++;
                j = i;
                if (!(src[nb] = (char *)malloc(sizeof(char) * (j - k + 1))))
                        return (0);
                cpy(src[nb], str, k, j);
                if (str[i] == '\0')
                        break ;
                nb++;
        }
        return (1);
}

char    **ft_split(char *str, char *charset) {

        char    **src;
        char    *tmp;
        int             i;
        int             j;

        tmp = str;
        i = -1;
        j = count(str, charset);
        if (!(src = (char **)malloc(sizeof(char *) * (j + 1))))
                return (0);
        if (!(get_strings(src, tmp, charset)))
                return (0);
        src[j] = 0;
        return (src);
}

int      main(void) {
    
  char *str = "comment tu vas";
  char *charset = " ";
 
  char **arr = ft_split(str, charset);
 
  int i = 0;
  while (arr[i]) {

      printf("%s\n", arr[i]);
      ++i;
  }
}

