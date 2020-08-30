学习最后一周的学习，经过这么久的学习，感觉逐渐上道，希望得到好的工作；
Rabin-Karp算法：
const int D = 256;
const int Q = 9997;

int RabinKarpSerach(string txt, string pat) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int patHash = 0, txtHash = 0;

    for (i = 0; i < M; i++) {
        patHash = (D * patHash + pat[i]) % Q;
        txtHash = (D * txtHash + txt[i]) % Q;
    }
    int highestPow = 1;  // pow(256, M-1)
    for (i = 0; i < M - 1; i++) 
        highestPow = (highestPow * D) % Q;

    for (i = 0; i <= N - M; i++) { // 枚举起点
        if (patHash == txtHash) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j])
                    break;
            }
            if (j == M)
                return i;
        }
        if (i < N - M) {
            txtHash = (D * (txtHash - txt[i] * highestPow) + txt[i + M]) % Q;
            if (txtHash < 0)
                txtHash += Q;
        }
    }

    return -1;
}
