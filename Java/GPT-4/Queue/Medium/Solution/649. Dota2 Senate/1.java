import java.util.*;

class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Queue<Integer> radiant = new LinkedList<>(), dire = new LinkedList<>();
        
        for(int i = 0; i<n; i++){
            if(senate.charAt(i) == 'R') radiant.add(i);
            else dire.add(i);
        }
        
        while(!radiant.isEmpty() && !dire.isEmpty()){
            int r = radiant.poll(), d = dire.poll();
            if(r < d) radiant.add(r + n);
            else dire.add(d + n);
        }
        
        return (radiant.size() > dire.size()) ? "Radiant" : "Dire";
    }
}

