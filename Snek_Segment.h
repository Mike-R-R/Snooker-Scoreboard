
#ifndef SNEK_SEGMENT
#define SNEK_SEGMENT

class SnekSegment{
	public:
		SnekSegment(int, int, int, int);
			
		~SnekSegment(){}
		
		int* advance_tail();
		
		bool tail_valid();
		
		bool advance_head();
		
		bool collides_with_segment(int, int);
		
		inline const int* get_coords(){
			return coords;
		}
		
		inline char get_direction(){
			return direction;
		}
		
	private:
		int coords[4];
		const char direction;
		
		char determine_directionality(int, int, int, int);
};

#endif
