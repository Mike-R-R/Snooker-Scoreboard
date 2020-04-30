
#include "Snek_Segment.h"

SnekSegment::SnekSegment(int x1, int y1, int x2, int y2) : direction(determine_directionality(x1, y1, x2, y2)) {
	coords[0] = x1;
	coords[1] = y1;
	coords[2] = x2;
	coords[3] = y2;
}

//SnekSegment::~SnekSegment(){}

/***
 * Advances the tail by one based on the direction
 */
int* SnekSegment::advance_tail(){
	int* tail =  new int[2];
	tail[0] = coords[2];
	tail[1] = coords[3];
	 
	switch(direction){
		case 'R':
			coords[2]++;
			break;
		case 'L':
			coords[2]--;
			break;
		case 'D':
			coords[3]++;
			break;
		case 'U':
			coords[3]--;
			break;
	}
	
	return tail;
}

bool SnekSegment::tail_valid(){
	if(coords[0] == coords[2] && coords[1] == coords[3]){
		return false;
	}
	
	return true;
}
		
/***
 * Advances the head coordiante by one based on the direction
 */
bool SnekSegment::advance_head(){
	switch(direction){
		case 'R':
			coords[0]++;
			break;
		case 'L':
			coords[0]--;
			break;
		case 'D':
			coords[1]++;
			break;
		case 'U':
			coords[1]--;
			break;
	}
	
	if(coords[0] < 0 || coords[0] > 31 || 
		coords[1] < 0 || coords[1] > 31){
		return false;
	}
	
	return true;
}

/***
 * Determines if the given coordinates collide with this segment
 */
bool SnekSegment::collides_with_segment(int x, int y){
	bool result = false;
	
	switch(direction){
		case 'R':
			if(x >= coords[2] && x <= coords[0])
				result = true;
			break;
		case 'L':
			if(x >= coords[0] && x <= coords[2])
				result = true;
			break;
		case 'D':
			if(x >= coords[3] && x <= coords[1])
				result = true;
			break;
		case 'U':
			if(x >= coords[1] && x <= coords[3])
				result = true;
			break;
	}

	return result;
}

/**
 * Private helper method to determine the direction of a snek segment
 */
char SnekSegment::determine_directionality(int x1, int y1, int x2, int y2){
	int xValue = x2 - x1;
	int yValue = y2 - y1;
	
	if(xValue != 0){
		if(xValue < 0){
			return 'R';
		} else{
			return 'L';
		}
	}
	else{
		if(yValue < 0){
			return 'D';
		} else{
			return 'U';
		}
	}
}
