import java.util.*;

class Solution {
    class State {
        int position;
        int speed;
        public State(int position, int speed) {
            this.position = position;
            this.speed = speed;
        }
    }
    
    public int racecar(int target) {
        Queue<State> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add(new State(0, 1));
        visited.add("0#1");
        int level = 0;

        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i = 0; i < size; i++) {
                State state = queue.poll();
                if(state.position == target) return level;
                State nextState = new State(state.position + state.speed, state.speed * 2);
                String key = nextState.position + "#" + nextState.speed;
                if(!visited.contains(key) && nextState.position > 0 && nextState.position < target * 2) {
                    queue.add(nextState);
                    visited.add(key);
                }
                nextState = new State(state.position, state.speed > 0 ? -1 : 1);
                key = nextState.position + "#" + nextState.speed;
                if(!visited.contains(key) && nextState.position > 0 && nextState.position < target * 2) {
                    queue.add(nextState);
                    visited.add(key);
                }
            }
            level++;
        }
        return -1;
    }
}
