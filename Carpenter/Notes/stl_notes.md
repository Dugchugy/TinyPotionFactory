# Binary stl files

```
UINT8[80]    – Header                 - 80 bytes
UINT32       – Number of triangles    - 04 bytes
foreach triangle                      - 50 bytes
    REAL32[3] – Normal vector         - 12 bytes
    REAL32[3] – Vertex 1              - 12 bytes
    REAL32[3] – Vertex 2              - 12 bytes
    REAL32[3] – Vertex 3              - 12 bytes
    UINT16    – Attribute byte count  - 02 bytes
end
```

Normal Vector points straight out from the face

 - should match with normals calculated using right hand rule (not nessicarily though)