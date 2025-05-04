Camera get_view_point()
{
	//YOU MIGHT NEED TO UPDATE THE LOCATION AND ROTATION POINTER IN THE NEXT UPDATE SO CHECK IT OUT DONT FORGET!
	Camera view_point{};
	uintptr_t location_pointer = read<uintptr_t>(cache::uworld + 0x160);
	uintptr_t rotation_pointer = read<uintptr_t>(cache::uworld + 0x170);
	FNRot fnrot{};
	fnrot.a = read<double>(rotation_pointer);
	fnrot.b = read<double>(rotation_pointer + 0x20);
	fnrot.c = read<double>(rotation_pointer + 0x1D0);
	view_point.location = read<Vector3>(location_pointer);
	view_point.rotation.x = asin(fnrot.c) * (180.0 / M_PI);
	view_point.rotation.y = ((atan2(fnrot.a * -1, fnrot.b) * (180.0 / M_PI)) * -1) * -1;
	view_point.fov = read<float>(cache::player_controller + 0x3AC) * 90.0f; //ITS 0x3AC since we use player controller if u use local player then use 0x4AC
	return view_point;
}
