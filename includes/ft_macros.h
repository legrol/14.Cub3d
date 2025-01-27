/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:08:07 by rdel-olm          #+#    #+#             */
/*   Updated: 2025/01/27 22:21:30 by rdel-olm         ###   ########.fr       */
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
# define SIDES_CUBE				6
# define RGB_VALID_MIN			1
# define RGB_VALID_MAX			255

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
# define OPEN_TEXTURE_ERR		"📖 Error, could not open texture filee!!!"
# define OPEN_ERR				"📖 Error opening source file!!!"
# define CLOSED_ERR				"📚 Error closing source file!!!"
# define OPEN_MAP_ERR			"🗺️ Error opening map."
# define READ_ERR				"❗Error reading line with GNL."
# define SPLIT_ERR				"❗Error in function ft_split."
# define MATRIX_TO_STR_ERR		"❗Error in function ft_matrix_to_str"
# define FT_STRTRIM_ERR			"❗Error in function ft_strtrim"
# define FT_SPLIT_ERR			"❗Error in ft_map_spliting with ft_split!"
# define MAP_ERR				"❗Error, map is missing!"
# define EXTRA_LINE_ERR			"❗Error, extra line in the map!"
# define IDENT_ERR				"❗Identifier "
# define IDENT2_ERR				" is not present."
# define IDENT3_ERR				"❗Invalid identifier."
# define RGB_ERR				"❗Wrong rgb value."
# define FORMAT_RGB_ERR			"❗Invalid RGB format."
# define ARG_RGB_ERR			"❗Wrong rgb argument."
# define LINE2_ERR				" in the line "
# define ARG_FILE_ERR			"❗Extra argument in file."
# define TEXTURE_ERR			"❗Wrong texture format."
# define TEXTURE_2_ERR			"Error in row: "
# define NORTH_ERR				"🌎 Error loading image of North Wall..."
# define SOUTH_ERR				"🌎 Error loading image of South Wall..."
# define EAST_ERR				"🌎 Error loading image of East Wall..."
# define WEST_ERR				"🌎 Error loading image of West Wall..."
# define CEIL					"C"
# define FLOOR					"F"
# define NORTH					"N"
# define SOUTH					"S"
# define EAST					"E"
# define WEST					"W"

// ======== Pdtes de incorporar a codigo  =====================================

# define MLX_INIT_ERR			"❗Error, something is wrong with mlx_init()"
# define MALLOC_ERR				"❌Ⓜⓐⓛⓛⓞⓒ Error creating malloc!!!"
# define MLX_ERR 				"4️⃣2️⃣📈📉 Error connecting to graphics server \
								MLX42!!!"
# define IMG_ERR 				"❌4️⃣2️⃣🎞️ Error initializing image MLX42!!!"
# define INIT_MAP_ERR			"🌎 Error initializing map!!!"
# define MATRIX1_ERR			"🔛 Wrong matrix line width!!!"
# define MLLC_CAM_ERR			"📽️ Error ailed to allocate memory for \
								camera!!!"
// ============================================================================

#endif