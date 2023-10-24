public class PowerOfFour {
    public bool Solution(int n)
    {
        int power = 1;

        while (power < n && power > 0)
            power <<= 2;

        return power == n;
    }
}
