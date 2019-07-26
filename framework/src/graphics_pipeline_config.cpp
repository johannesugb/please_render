namespace cgb
{
	// Set sensible defaults:
	graphics_pipeline_config::graphics_pipeline_config()
		: mPipelineSettings{ pipeline_settings::nothing } // unsupported right now anyways
		, mPrimitiveTopology{ primitive_topology::triangles } // triangles after one another
		, mRasterizerGeometryMode{ rasterizer_geometry_mode::rasterize_geometry } // don't discard, but rasterize!
		, mPolygonDrawingModeAndConfig{ polygon_drawing::config_for_filling() } // Fill triangles
		, mCullingMode{ culling_mode::cull_back_faces } // Cull back faces
		, mFrontFaceWindingOrder{ front_face::define_front_faces_to_be_counter_clockwise() } // CCW == front face
		, mDepthClampBiasConfig{ depth_clamp_bias::config_nothing_special() } // no clamp, no bias, no factors
		, mDepthTestConfig{ depth_test::enabled() } // enable depth testing
		, mDepthWriteConfig{ depth_write::enabled() } // enable depth writing
		, mDepthBoundsConfig{ depth_bounds::disable() }
		// TODO: Proceed here with defining default parameters
		, mColorBlendingSettings{ color_blending_settings::disable_logic_operation{} }
		
	{
	}
}
