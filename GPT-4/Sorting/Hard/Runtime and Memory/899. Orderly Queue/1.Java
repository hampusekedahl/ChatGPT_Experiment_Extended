class Solution {
    public String orderlyQueue(String s, int k) {
        if (k > 1) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            return new String(ca);
        } else {
            String res = s;
            for (int i = 1; i < s.length(); i++) {
                String tmp = s.substring(i) + s.substring(0, i);
                if (res.compareTo(tmp) > 0) res = tmp;
            }
            return res;
        }
    }
}
