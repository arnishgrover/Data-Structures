import java.util.*;

class HuffCode {
	
	PriorityQueue<HuffNode> q;
	HashMap<Character, String> map;
	private HashMap<Character, Integer> hash;
	final String in_string;
	private String coded;
	
	private class HuffNode implements Comparable<HuffNode>{
		char data;
		HuffNode left, right;
		int count;
		HuffNode(char data, int count) {
			this.count = count;
			this.data = data;
		}
		HuffNode(int count) {
			this.data = '#';
			this.count = count;
		}
		public int compareTo(HuffNode arg0) {
			
			return this.count - arg0.count;
		}
		
	
	}
	HuffCode(String initial_string) {
		hash = new HashMap<>();
		q = new PriorityQueue<>();
		map  = new HashMap<>();
		in_string = initial_string;
		
		for(int i = 0; i < initial_string.length(); i++) {
			if(hash.containsKey(initial_string.charAt(i))) {
				int t = hash.get(initial_string.charAt(i));
				hash.put(initial_string.charAt(i), t+1);
			}
			else {
				hash.put(initial_string.charAt(i), 1);
			}
		}
		
		create_root(hash);
	}
	private void create_root(HashMap<Character, Integer> map) {
		for(char a: map.keySet()) {
			q.add(new HuffNode(a , map.get(a)));
		}
		while(q.size() > 1) {
			HuffNode a = q.poll();
			HuffNode b = q.poll();
			int new_count = a.count + b.count;
			
			HuffNode new_node = new HuffNode(new_count);
			new_node.left = a;
			new_node.right = b;
			
			q.add(new_node);
			
		}
		create_codes();
		
	}
	private void create_codes() {
		HuffNode root = q.peek();
		char[] str = new char[100];
		//str[0] = '0';
		create_codes(root, str, 0);
		code(in_string);
	}
	private void create_codes(HuffNode root, char[] str, int idx) {
		if(root == null) {
			return;
		}
		if(root.data != '#') {
			String res = String.valueOf(str);
			res = res.substring(0, idx);
			//System.out.println(root.data + " " + res);
			map.put(root.data, res);
			return;
		}
		str[idx] = '0';
		create_codes(root.left, str, idx+1);
		str[idx] = '1';
		create_codes(root.right, str, idx+1);
		
	}
		
	private void code(String main) {
		String coded = "";
		for(int i = 0; i < main.length(); i++) {
			coded += map.get(main.charAt(i));
			//System.out.println(main.charAt(i) + "  " + map.get(main.charAt(i)));
		}
		this.coded = coded;
	}
	
	public String decode() {
		
		HuffNode root = q.peek();
		String ans = "";
		for(int i = 0; i < coded.length(); i++) {
			if(coded.charAt(i) == '0') {
				root = root.left;
			}
			else { 
				root = root.right;
			}
			
			if(root.left == null && root.right == null) {
				ans += root.data;
				root = q.peek();
			}
		}
		return ans;
	}
	@SuppressWarnings("unused")
	private void display() {
		for(char a: map.keySet()) {
			System.out.println(a + " " + map.get(a));
		}
	}
	
}
public class HuffmanCode {
	public static void main(String[] args) {
		String to_be_coded = "my name is arnish";
		HuffCode c = new HuffCode(to_be_coded);
	
		
		System.out.println(c.decode());
	}
}
