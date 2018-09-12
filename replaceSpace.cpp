class ReplaceSpace
{
  public:
    void replaceSpace(char *str, int length)
    {
        // 统计需要替换的空格数
        char *t = str;
        int strLength = 0;
        int count = 0;

        // 统计
        while (*t != '\0')
        {
            strLength++;
            if (*t == ' ')
            {
                count++;
            }
            t++;
        }

        int finalLength = strLength + count * 2;

        if (finalLength == strLength || finalLength > length)
            return;

        // 从后往前替换
        int p, q;
        for (p = finalLength, q = strLength; q >= 0; q--)
        {
            if (str[q] == ' ')
            {
                str[p--] = '0';
                str[p--] = '2';
                str[p--] = '%';
            }
            else
            {
                str[p--] = str[q];
            }
        }
    }
}