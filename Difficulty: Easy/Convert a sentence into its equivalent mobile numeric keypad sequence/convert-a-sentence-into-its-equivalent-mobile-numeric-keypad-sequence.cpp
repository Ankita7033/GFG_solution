string printSequence(string S) {
    string keypad[] = {
        "2", "22", "222",      // A, B, C
        "3", "33", "333",      // D, E, F
        "4", "44", "444",      // G, H, I
        "5", "55", "555",      // J, K, L
        "6", "66", "666",      // M, N, O
        "7", "77", "777", "7777", // P, Q, R, S
        "8", "88", "888",      // T, U, V
        "9", "99", "999", "9999"  // W, X, Y, Z
    };

    string ans = "";

    for (char ch : S) {
        if (ch == ' ')
            ans += "0";
        else
            ans += keypad[ch - 'A'];
    }

    return ans;
}

