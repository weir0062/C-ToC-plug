Shader "Tv" {
	Properties{
		_MainTex("Base (RGB)", 2D) = "white" {}
	    _FOVColor("Field Of View Color", Color) = (1, 1, 1)
		_MainColor("MainColor", Color) = (1, 1, 1)
		_BallPosition("_BallPosition",  Vector) = (0,0,0,0)
		_PaddlePosition("PaddlePosition",  Vector) = (0,0,0,0)
		_Direction("Direction",  Vector) = (0,0,0,0)
		_Angle("Angle", Range(0, 360)) = 45
	}
		SubShader{
		Tags{ "RenderType" = "Diffuse" }

		CGPROGRAM
#pragma surface surf Lambert

	sampler2D _MainTex;
	fixed3 _FOVColor; //Precision
	fixed3 _MainColor;
	float4 _PaddlePosition;
	float4 _BallPosition;
	float4 _Direction;
	float _Angle;

	struct Input {
		float2 uv_MainTex;
		float3 worldPos;
	};

	bool isPointInTriangle(float2 p1, float2 p2, float2 p3, float2 pointInQuestion)
	{
		float denominator = ((p2.y - p3.y) * (p1.x - p3.x) + (p3.x - p2.x) * (p1.y - p3.y));
		float a = ((p2.y - p3.y) * (pointInQuestion.x - p3.x) + (p3.x - p2.x) * (pointInQuestion.y - p3.y)) / denominator;
		float b = ((p3.y - p1.y) * (pointInQuestion.x - p3.x) + (p1.x - p3.x) * (pointInQuestion.y - p3.y)) / denominator;
		float c = 1 - a - b;

		return 0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1;
	}

	void surf(Input IN, inout SurfaceOutput o) {
		half4 c = tex2D(_MainTex, IN.uv_MainTex);

		float angle = _Angle;
		float radians = angle * (3.14 / 180);
		float distanceVar = 0.1;
		float3 BasePoint = _PaddlePosition.xyz;
		


		// Unit Circle
		float3 TRightPoint = (float3(cos(radians), 0, sin(radians)) * distanceVar) + BasePoint;
		float3 TLeftPoint = (float3(cos(3.14 - radians ), 0, sin(3.14 - radians)) * distanceVar) + BasePoint;

		float3 BRightPoint = (float3(cos(6.28 - radians), 0, sin(6.28 - radians)) * distanceVar) + BasePoint;
		float3 BLeftPoint = (float3(cos(3.14 + radians), 0, sin(3.14 + radians)) * distanceVar) + BasePoint;

		float3 PointInQuestion = IN.worldPos;
		
		float radius = 0.03;
		float dist = distance(_BallPosition, IN.worldPos);
	
		c.rgb *= _MainColor;
		
		if(isPointInTriangle(TRightPoint.xz, TLeftPoint.xz, BLeftPoint.xz, PointInQuestion.xz)
		  || isPointInTriangle(TRightPoint.xz, BLeftPoint.xz, BRightPoint.xz, PointInQuestion.xz)
			|| dist < (radius))
			o.Albedo = c.rgb * _FOVColor;
		else
		{
			
			o.Albedo = c.rgb;
		}

		o.Alpha = c.a;
	}
	ENDCG
	}
		FallBack "Diffuse"
}
