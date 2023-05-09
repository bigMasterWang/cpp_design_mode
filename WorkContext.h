

class WorkState;


class WorkContext
{
private:
	WorkState* w;
	float hour;
public:
	void set_hour(float h) { hour = h; };
	inline float get_hour() { return hour; };
	void setWorkState(WorkState* _w) { w = _w; };
	WorkState* getWorkState() { return w; };
};
