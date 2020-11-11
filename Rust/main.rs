/*
 * File: main.rs
 * File Created: 10/11/2020 18:24
 * Author: Nicolas Huynh at (nico.huynh@gmail.com)
 * -----
 * Description: <Desc of the file goal(s)>
 * Copyright 2020 NH
 */






fn get_distance(pt1_lon : f64, pt1_lat : f64, pt2_lon : f64, pt2_lat : f64,) -> f64 {
	let earth_radius_kilometer = 6371.0_f64;

	let delta_latitude = (pt1_lat - pt2_lat).to_radians();
	let delta_longitude = (pt1_lon - pt2_lon).to_radians();

	let central_angle_inner = (delta_latitude / 2.0).sin().powi(2)
		+ pt1_lat.to_radians().cos() * pt2_lat.to_radians().cos() * (delta_longitude / 2.0).sin().powi(2);
	let central_angle = 2.0 * central_angle_inner.sqrt().asin();

	earth_radius_kilometer * central_angle;
}