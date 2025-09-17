using System;
using System.Text;

class Program
{
    static int Solve(int k, int x) => x << (k-2);

    static void Main()
    {
        string? line = Console.ReadLine();
        if (line == null)
            return;
        int t = int.Parse(line);
        var sb = new StringBuilder();
        while (t-- > 0)
        {
            string? ln = Console.ReadLine();
            while (ln != null && ln.Trim().Length == 0)
                ln = Console.ReadLine();
            if (ln == null)
                break;
            var parts = ln.Split((char[])null!, StringSplitOptions.RemoveEmptyEntries);
            int k = int.Parse(parts[0]);
            int x = int.Parse(parts[1]);
            sb.AppendLine(Solve(k, x).ToString());
        }
        Console.Write(sb.ToString());
    }
}
