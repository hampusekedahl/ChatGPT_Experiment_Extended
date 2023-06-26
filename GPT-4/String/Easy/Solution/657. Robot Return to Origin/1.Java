class Solution {
    public boolean judgeCircle(String moves) {
        int vertical = 0, horizontal = 0;
        for(char c : moves.toCharArray()){
            switch(c){
                case 'U': vertical++; break;
                case 'D': vertical--; break;
                case 'R': horizontal++; break;
                case 'L': horizontal--; break;
            }
        }
        return vertical == 0 && horizontal == 0;
    }
}
