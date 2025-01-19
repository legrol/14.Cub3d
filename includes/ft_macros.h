/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:08:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/19 21:29:25 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

/**
 * Standard image sizes in pixels
 * 	1920 * 1080 HDTV, 16:9, presentations, RRSS images
 *  1280 * 720 HD, 16:9, photography and cinema
 *  1080 * 1080 RRSS publications and profile images, 1:1
 * 
 * FOV => Filed of Vision
 * 
 */

# define WIDTH					1920
# define HEIGHT					1280
# define WALL_SIZE				640
# define FOV					60

# define INIT_ERR				"42Cub3d say: "
# define ARROW					"==> "
# define NUM_ARGV_ERR			"❗1️⃣ Incorrect number of arguments, expected \
								one."
# define SHORT_NAME_ERR			"🗺️ Map name is very short!!!"
# define EXT_ERR				"❌ⓔⓧⓣ File extension error!!!"
# define FLOOR_OR_SKY_ERR		"❗Error rendering the ground or the \
								sky."
# define IMG_TO_WINDOW_ERR		"❗Error in function while rendering \
								process."
# define INV_CHAR_ERR			"❗Invalid character in first line."
# define INV_CHAR2_ERR			"❗Invalid character in last line."
# define CHAR1_ERR				"❌ⓒⓗⓐⓡ Wrong character "
# define CHAR2_ERR				"... at map line "
# define CHAR3_ERR				" in the position "
# define SIDE_LEFT_ERR			"❗Map left side isn't closed properly."
# define SIDE_RIGHT_ERR			"❗Map right side isn't closed properly."
# define LINE_ERR				"Error at line: "
# define FORB_SPC_ERR			"❗Forbidden space "
# define FORB_SPC2_ERR			"on the line "
# define PLAYERS_0_ERR			"❗No player on the map. There must be one."
# define PLAYERS_NO1_ERR		"❗Too many players on the map. There must be \
								one."
# define OPEN_ERR				"📖 Error opening source file!!!"
# define CLOSED_ERR				"📚 Error closing source file!!!"
# define OPEN_MAP_ERR			"🗺️ Error opening map."

// ======== Pdtes de incorporar a codigo  =====================================

# define MALLOC_ERR				"❌Ⓜⓐⓛⓛⓞⓒ Error creating malloc!!!"
# define MLX_ERR 				"4️⃣2️⃣📈📉 Error connecting to graphics server \
								MLX42!!!"
# define IMG_ERR 				"❌4️⃣2️⃣🎞️ Error initializing image MLX42!!!"
# define INIT_MAP_ERR			"🌎 Error initializing map!!!"
# define MATRIX1_ERR			"🔛 Wrong matrix line width!!!"
# define MATRIX2_ERR			"❗🔛 FdF file has irregular width!!!"
# define MLLC_CAM_ERR			"📽️ Error ailed to allocate memory for \
								camera!!!"
// ============================================================================

#endif