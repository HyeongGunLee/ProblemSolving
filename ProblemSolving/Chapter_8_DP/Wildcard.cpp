int cache[101][101];
string W, S;

bool match(int w, int s) {
    int pos = 0;
    int& ret = cache[w][s];
    if (ret != -1) return ret;

    /*
while (w < w.size() && s < s.size() && (W[w] == ‘?’ || W[w] == S[s])) {
    s++;
    w++;
}
*/
    if (w < w.size() && s<s.size() && (W[w] == ‘?’ || W[w] == S[s])) {
        return ret = match(w+1, s+1);
    }


    if (w == W.size()) return ret = W.size() == S.size();

/*
if (W[w] == ‘*’) {
	for (int skip = 0; s+skip < S.size(); skip++) {
		if (match(w+1, s+skip))
			return ret = 1;
}
}
*/

    if (W[w] == ‘*’) {
        if (match(w+1, s) || ( match(w, s+1) && s < S.size())
            return ret = 1;
    }

    return 0;
}
