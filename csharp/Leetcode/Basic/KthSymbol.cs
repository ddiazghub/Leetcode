using System.Numerics;
using System.Text;

public class KthSymbol
{
    public static IEnumerable<string> Table(int rows = 30)
    {
        var str = "0";
        yield return str;

        for (int i = 1; i < rows; i++)
        {
            str = string.Join("", str.Select(ch => ch == '0' ? "01" : "10"));
            yield return str;
        }
    }

    public int FindKthSymbol(int k)
    {
        var str = new StringBuilder("01");

        while (str.Length < k)
        {
            int limit = str.Length;

            for (int i = limit / 2; i < limit; i++)
                str.Append(str[i] == '0' ? "01" : "10");
        }

        return str[k - 1] == '0' ? 0 : 1;
    }

    public int TLE(int n, int k) =>
        k switch
        {
            1 or 2 => k,
            _ => FindKthSymbol(k)
        };

    public int EpicFail(int n, int k)
    {
        int bitcount = 1;
        BigInteger mask = BigInteger.Zero;

        while (bitcount < k)
        {
            int bitcountMask = (1 << bitcount) - 1;
            mask = (mask << bitcount) | (~mask & bitcountMask);
            bitcount <<= 1;
        }

        int indexMask = 1 << (bitcount - k);

        return (mask & indexMask) > 0 ? 1 : 0;
    }

    private bool FindKthSymbol(bool current, int k, int symbols)
    {
        if (symbols == 1)
            return current;

        int half = symbols / 2;

        if (k < half)
            return FindKthSymbol(current, k, half);
        else
            return FindKthSymbol(!current, k - half, half);
    }

    public int Solution(int n, int k)
    {
        int symbols = 1 << (int)Math.Ceiling(Math.Log2(k));

        return FindKthSymbol(false, k - 1, symbols) ? 1 : 0;
    }
}
